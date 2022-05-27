// System Programming Example: Using the waitpid() system call
// Author: Andrew Jarombek
// Date: 5/26/2022

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int main() {
    pid_t pid = getgid();
    printf("The current process id is: %d\n", pid);

    int status;
    pid = fork();

    if (pid > 0) {
        printf("Parent process of child with id %d\n", pid);

        pid = waitpid(pid, &status, 0);

        if (pid == -1) {
            perror("wait");
            return 1;
        }
    } else if (!pid) {
        printf("Child process\n");
        int ret = execlp("echo", "echo", "Hello!", NULL);

        if (ret == -1) {
            perror("execvp");
            exit(EXIT_FAILURE);
        }

        exit(EXIT_SUCCESS);
    } else {
        perror("fork");
        return 1;
    }

    return 0;
}