// System Programming Example: Read and Write to a file
// Author: Andrew Jarombek
// Date: 2/23/2022

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

void readBuffer(int fd);

int main() {
    int fd = open("./upcoming_races.csv", O_RDWR, 0644);
    readBuffer(fd);

    const char *buf = "\nBoston Marathon,Road,Marathon,4/18/2022";
    ssize_t ret;

    while ((ret = write(fd, buf, strlen(buf))) != 0) {
        if (ret == -1) {
            if (errno == EINTR)
                continue;

            perror("write");
            break;
        }

        buf += ret;
    }

    if (close(fd) == -1)
        perror("close");

    fd = open("./upcoming_races.csv", O_RDWR, 0644);
    readBuffer(fd);

    if (close(fd) == -1)
        perror("close");

    return 0;
}

void readBuffer(int fd) {
    char buffer[BUFSIZ];
    ssize_t ret;
    int index = 1;

    while ((ret = read(fd, &buffer, BUFSIZ)) != 0) {
        if (ret == -1) {
            if (errno == EINTR)
                continue;

            perror("read");
            break;
        }

        printf("Loop through file: %d\n", index);
        printf("%s\n", buffer);

        index++;
    }
}