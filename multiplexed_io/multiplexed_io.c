// System Programming Example: Perform Multiplexed I/O
// Author: Andrew Jarombek
// Date: 4/2/2022

#include <stdio.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>
#include <string.h>

#define TIMEOUT 5

char* get_time() {
    time_t raw_time;
    struct tm *time_info;

    time(&raw_time);
    time_info = localtime(&raw_time);
    return asctime(time_info);
}

int main() {
    // One way to perform Multiplexed I/O is the select() system call.
    // select() should not be used in modern applications, because it only accepts file descriptors with numbers below 1024.
    // Modern computers almost always have an open file count greater than 1024, making select() unusable.
    // Reference: https://man7.org/linux/man-pages/man2/select.2.html
    struct timeval tv;
    fd_set read_fds;
    int ret;

    // Add the standard input file descriptor into a set of type fd_set, which is used in select()
    FD_ZERO(&read_fds);
    FD_SET(STDIN_FILENO, &read_fds);

    tv.tv_sec = TIMEOUT;
    tv.tv_usec = 0;

    // Call select()
    printf("Invoking select(): %s", get_time());
    ret = select(STDIN_FILENO + 1, &read_fds, NULL, NULL, &tv);

    char* message = "Hello!\n";
    int write_result = write(STDIN_FILENO, message, strlen(message));

    if (write_result == -1) {
        perror("write");
    }

    close(STDIN_FILENO);

    if (ret == -1) {
        perror("select");
        return 1;
    } else if (!ret) {
        printf("Timeout reached for select(): %s", get_time());
    }

    // Check to see if standard input is ready to be read.
    if (FD_ISSET(STDIN_FILENO, &read_fds)) {
        char buf[BUFSIZ];
        int len;

        len = read(STDIN_FILENO, buf, BUFSIZ);

        if (len == -1) {
            perror("read");
            return 1;
        }

        if (len) {
            buf[len] = '\0';
            printf("read: %s\n", buf);
        }
    } else {
        printf("STDIN not in the file descriptor set for select(): %s", get_time());
    }

    // Use select() to sleep for a minute.  There are better ways to sleep then select(), but it still works.
    struct timeval sleep_tv = {.tv_sec = 1, .tv_usec = 0};

    printf("Sleeping for one second.\nTime Before Sleep: %s", get_time());
    select(0, NULL, NULL, NULL, &sleep_tv);
    printf("Time After Sleep: %s", get_time());

    return 0;
}