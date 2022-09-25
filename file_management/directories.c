// System Programming Example: Working with directories.
// Author: Andrew Jarombek
// Date: 9/24/2022

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <dirent.h>
#include <errno.h>

void print_cwd();
void read_files();

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

    // Make a new directory called 'temp' within the current working directory.
    ret = mkdir("temp", 777);

    if (ret) {
        perror("mkdir");
        return 1;
    }

    printf("\nFiles in current directory after creating 'temp':\n");

    // Read all the files/directories in the current directory.
    // Same as running an 'ls' command without any flags.
    read_files();

    ret = rmdir("temp");

    if (ret) {
        perror("readdir");
        return 1;
    }

    printf("\nFiles in current directory after deleting 'temp':\n");
    read_files();
}

void print_cwd() {
    char cwd[BUFSIZ];

    if (!getcwd(cwd, BUFSIZ)) {
        perror("getcwd");
        exit(EXIT_FAILURE);
    }

    printf("Current Working Directory: %s\n", cwd);
}

void read_files() {
    struct dirent *entry;
    DIR *dir = opendir(".");

    errno = 0;
    while ((entry = readdir(dir)) != NULL) {
        printf("%s\n", entry->d_name);
    }

    if (errno && !entry) {
        perror("readdir");
        exit(EXIT_FAILURE);
    }
}