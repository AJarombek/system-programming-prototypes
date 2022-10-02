// System Programming Example: Using inotify, an interface for monitoring file events.
// Author: Andrew Jarombek
// Date: 10/1/2022

#include <unistd.h>
#include <sys/inotify.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

void remove_inotify_watch(int fd, int wd);
void create_file(char* filename);
void read_inotify_events(int fd);

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

    read_inotify_events(fd);

    // Add a watch on the current directory.  Get events for read and writes of files.
    wd = inotify_add_watch(fd, ".", IN_OPEN | IN_ACCESS | IN_MODIFY);

    if (wd == -1) {
        perror("inotify_add_watch");
        return 1;
    }

    printf("inotify watch descriptor for reads and writes: %d\n", wd);

    // Open a file
    int first_txt_fd = open("./first.txt", O_RDWR, 0644);

    // Write to a file
    const char *buf = "Hello";
    ssize_t r;

    while ((r = write(first_txt_fd, buf, strlen(buf))) != 0) {
        if (r == -1) {
            if (errno == EINTR)
                continue;

            perror("write");
            break;
        }

        buf += r;
    }

    read_inotify_events(fd);

    ret = close(first_txt_fd);

    if (fd == -1) {
        perror("close");
        return 1;
    }

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

void read_inotify_events(int fd) {
    char buf[BUFSIZ];
    ssize_t len = read(fd, buf, BUFSIZ);
    ssize_t i = 0;

    while (i < len) {
        struct inotify_event *event = (struct inotify_event*) &buf[i];
        printf("event wd = %d\n", event->wd);
        printf("event mask = %d\n", event->mask);
        printf("event cookie = %d\n", event->cookie);
        printf("event len = %d\n", event->len);

        if (event->len)
            printf("event name = %s\n", event->name);

        if (event->mask & IN_CREATE)
            printf("event type: a file was created\n");
        if (event->mask & IN_OPEN)
            printf("event type: a file was opened\n");
        if (event->mask & IN_ACCESS)
            printf("event type: a file was read\n");
        if (event->mask & IN_MODIFY)
            printf("event type: a file was modified\n");

        i += sizeof(struct inotify_event*) + event->len;
    }
}
