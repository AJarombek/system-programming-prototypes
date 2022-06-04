// System Programming Example: Yielding execution to the process schedule.
// Author: Andrew Jarombek
// Date: 6/3/2022

#include <sched.h>
#include <stdio.h>

int main() {
    // sched_yield() tells the Linux process scheduler to suspend the currently running process so
    // that a new process can be selected to run.
    // Linux is a preemptive scheduler, so sched_yield() is very rarely needed
    if (sched_yield())
        perror("sched_yield");

    return 0;
}