// System Programming Example: Perform Multiplexed I/O using poll()
// Author: Andrew Jarombek
// Date: 4/23/2022

#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <poll.h>

#define TIMEOUT 5

char* get_time() {
    time_t raw_time;
    struct tm *time_info;

    time(&raw_time);
    time_info = localtime(&raw_time);
    return asctime(time_info);
}

int main() {
    struct pollfd fds[2];
    int ret;

    fds[0].fd = STDIN_FILENO;
    fds[1].events = POLLIN;

    fds[0].fd = STDOUT_FILENO;
    fds[1].events = POLLOUT;

    // Call poll()
    printf("Invoking poll(): %s", get_time());
    ret = poll(fds, 2, TIMEOUT * 1000);

    if (ret == -1) {
        perror("poll");
        return 1;
    } else if (!ret) {
        printf("Timeout reached for poll(): %s", get_time());
    }

    if (fds[0].revents & POLLIN) {
        printf("Stdin is readable \n");
    } else {
        printf("Stdin is NOT readable \n");
    }

    if (fds[1].revents & POLLOUT) {
        printf("Stdout is writable \n");
    } else {
        printf("Stdout is NOT writable \n");
    }

    return 0;
}