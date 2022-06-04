// System Programming Example: Setting the priority of a process for the scheduler.
// Author: Andrew Jarombek
// Date: 6/3/2022

#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <sys/resource.h>

int main() {
    // Linux determines the amount of time a process gets to run on the CPU based on priorities.
    // Priorities are determined by a nice value.  The lower the nice value, the more time a process gets to run.
    // Get the current nice value of the process.
    int val = nice(0);
    printf("The current process nice value is %d\n", val);

    // Change the nice value of the process.
    val = 5 - val;
    errno = 0;

    int ret = nice(val);

    if (ret == -1 && errno != 0) {
        perror("nice");
    } else {
        printf("The current process nice value is updated to %d\n", ret);
    }

    // Other ways to get and set nice values.
    ret = setpriority(PRIO_PROCESS, 0 , 10);

    if (ret == -1)
        perror("setpriority");

    int priority = getpriority(PRIO_PROCESS, 0);
    printf("The current process nice value is updated to %d\n", priority);

    return 0;
}