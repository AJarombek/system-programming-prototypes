// System Programming Example: Working with directories.
// Author: Andrew Jarombek
// Date: 9/24/2022

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

void print_cwd();

int main() {
    print_cwd();

    // Switch to a different working directory,
    // and then return to the initial working directory.
    int wd_fd = open(".", O_RDONLY);

    if (wd_fd == -1) {
        perror("open");
        return 1;
    }

    int ret = chdir("..");

    if (ret) {
        perror("chdir");
        return 1;
    }

    print_cwd();

    ret = fchdir(wd_fd);

    if (ret) {
        perror("fchdir");
        return 1;
    }

    print_cwd();

    ret = close(wd_fd);

    if (ret) {
        perror("close");
        return 1;
    }
}

void print_cwd() {
    char cwd[BUFSIZ];

    if (!getcwd(cwd, BUFSIZ)) {
        perror("getcwd");
        exit(EXIT_FAILURE);
    }

    printf("Current Working Directory: %s\n", cwd);
}