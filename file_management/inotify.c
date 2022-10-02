// System Programming Example: Using inotify, an interface for monitoring file events.
// Author: Andrew Jarombek
// Date: 10/1/2022

#include <unistd.h>
#include <sys/inotify.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

void remove_inotify_watch(int fd, int wd);
void create_file(char* filename);

int main() {
    int ret;
    int fd = inotify_init1(0);

    if (fd == -1) {
        perror("inotify_init1");
        return 1;
    }

    printf("inotify file descriptor: %d\n", fd);

    // Add a watch on the current directory.  Get events for the creation of files.
    int wd = inotify_add_watch(fd, ".", IN_CREATE);

    if (wd == -1) {
        perror("inotify_add_watch");
        return 1;
    }

    printf("inotify watch descriptor for file creation: %d\n", wd);

    // Create two files in the current directory.
    create_file("first.txt");
    create_file("second.txt");

    // Add a watch on the current directory.  Get events for read and writes of files.
    wd = inotify_add_watch(fd, ".", IN_ACCESS | IN_MODIFY);

    if (wd == -1) {
        perror("inotify_add_watch");
        return 1;
    }

    printf("inotify watch descriptor for reads and writes: %d\n", wd);

    remove_inotify_watch(fd, wd);

    ret = close(fd);

    if (fd == -1) {
        perror("close");
        return 1;
    }
}

void remove_inotify_watch(int fd, int wd) {
    int ret = inotify_rm_watch(fd, wd);

    if (ret) {
        perror("inotify_rm_watch");
        exit(EXIT_FAILURE);
    }

    printf("remove watch with descriptor %d from inotify with descriptor %d\n", wd, fd);
}

void create_file(char* filename) {
    int fd = creat(filename, 0644);

    if (fd == -1) {
        printf("Error creating file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    printf("Created file %s with descriptor %d\n", filename, fd);
}
