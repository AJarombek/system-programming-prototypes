// System Programming Example: Perform basic process management
// Author: Andrew Jarombek
// Date: 5/22/2022

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int main() {
    pid_t pid = getpid();
    printf("The current process id is: %d\n", pid);

    int status;

    pid = fork();

    if (pid > 0) {
        printf("Parent process of child with id %d\n", pid);

        pid = wait(&status);

        if (pid == -1) {
            perror("wait");
            return 1;
        }

        if (WIFEXITED(status)) {
            printf("Child process terminated normally with exit status %d\n", WEXITSTATUS(status));
        }

        if (WIFSIGNALED(status)) {
            printf("Child process killed by signal %d %s\n", WTERMSIG(status), WCOREDUMP(status) ? "(dumped core)" : "");
        }

        if (WIFSTOPPED(status)) {
            printf("Child process stopped by signal %d\n", WSTOPSIG(status));
        }

        if (WIFCONTINUED(status)) {
            printf("Child process continued\n");
        }

        char* args[] = {"ls", NULL};
        int ret = execvp("ls", args);

        if (ret == -1) {
            perror("execvp");
            return 1;
        }
    } else if (!pid) {
        printf("Child process\n");

        int ret = execlp("pwd", "pwd", NULL);

        if (ret == -1) {
            perror("execlp");
            exit(EXIT_FAILURE);
        }

        exit(EXIT_SUCCESS);
    } else {
        perror("fork");
        return 1;
    }

    return 0;
}