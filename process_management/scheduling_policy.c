// System Programming Example: Checking the scheduling policy of a process.
// Author: Andrew Jarombek
// Date: 6/11/2022

#include <sched.h>
#include <stdio.h>

int main() {
    int policy = sched_getscheduler(0);

    if (policy == -1) {
        perror("sched_getscheduler");
        return 1;
    }

    if (policy == SCHED_OTHER) {
        printf("Process has a normal scheduling policy.\n");
    } else {
        printf("Process has a real-time scheduling policy.\n");
    }

    return 0;
}