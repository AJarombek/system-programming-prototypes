// System Programming Example: Creating a daemon using a shorthand library call
// Author: Andrew Jarombek
// Date: 5/29/2022

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

int main() {
    // Step 2: Create the daemon.
    int ret = daemon(0, 0);

    if (ret == -1) {
        printf("Failed to create daemon");
        return -1;
    }

    // Step 2: Run the daemon.
    while (1) {
        int fd = creat("/grandmas_blanket.log", 0644);
        char* message = "Grandma's blanket keeps those who use it snug, and I try to make blankets that do the same.\n";

        int ret = write(fd, message, strlen(message));

        if (ret == -1) {
            return -1;
        }

        // Sleep for 10 seconds
        struct timeval sleep_tv = {.tv_sec = 10, .tv_usec = 0};
        select(0, NULL, NULL, NULL, &sleep_tv);
    }
}