// System Programming Example: Using the system() system call to run a bash command in a new process.
// Author: Andrew Jarombek
// Date: 5/30/2022

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int main() {
    // The system() system call is good for one-off commands that are run in a separate process.
    // The Bash command prints mileage plans from the month of June in reverse order.
    int ret = system("cat mileage_plan.txt | grep -v 5/ | sort -r");

    if (WIFSIGNALED(ret) && WTERMSIG(ret) == SIGINT || WTERMSIG(ret) == SIGQUIT) {
        printf("system() invocation failed");
        return -1;
    }

    return 0;
}