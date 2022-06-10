// System Programming Example: Processor affinity for running a process on certain CPU(s).
// Author: Andrew Jarombek
// Date: 6/9/2022

#define _GNU_SOURCE

#include <sched.h>
#include <stdio.h>

int main() {
    cpu_set_t set;

    CPU_ZERO(&set);

    int ret = sched_getaffinity(0, sizeof(cpu_set_t), &set);

    if (ret == -1) {
        perror("sched_getaffinity");
        return 1;
    }

    // Get a set of all the CPUs available to run the process on the machine.
    // On my Debian container, there are four CPUs.
    int cpu_count = 0;

    for (int i = 0; i < CPU_SETSIZE; i++) {
        int cpu = CPU_ISSET(i, &set);

        if (cpu) {
            cpu_count++;
            printf("CPU #%d is available to run the process.\n", i);
        }
    }

    // Change the CPU affinity.  Allow the process to run on CPUs #0 and #2, but not on CPUs #1 and #3.
    CPU_ZERO(&set);
    CPU_SET(0, &set);
    CPU_CLR(1, &set);
    CPU_SET(2, &set);
    CPU_CLR(3, &set);

    ret = sched_setaffinity(0, sizeof(cpu_set_t), &set);

    if (ret == -1) {
        perror("sched_setaffinity");
        return 1;
    }

    for (int i = 0; i < cpu_count; i++) {
        int cpu = CPU_ISSET(i, &set);

        if (cpu) {
            printf("CPU #%d is still available to run the process.\n", i);
        } else {
            printf("CPU #%d is unavailable to run the process.\n", i);
        }
    }

    return 0;
}