// System Programming Example: Perform Multiplexed I/O
// Author: Andrew Jarombek
// Date: 4/2/2022

#include <stdio.h>
#include <unistd.h>

#define TIMEOUT 5

int main() {
    struct timeval tv;
    fd_set readfds;
    int ret;

    FD_ZERO(&readfds);
    FD_SET(STDIN_FILENO, &readfds);

    tv.tv_sec = TIMEOUT;
    tv.tv_usec = 0;

    ret = select(STDIN_FILENO + 1, &readfds, NULL, NULL, &tv);

    if (ret == -1) {
        perror("select");
        return 1;
    } else if (!ret) {
        printf("%d seconds elapsed.\n", TIMEOUT);
        return 0;
    }

    return 0;
}