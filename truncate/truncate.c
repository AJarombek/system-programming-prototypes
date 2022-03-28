// System Programming Example: Truncate a file
// Author: Andrew Jarombek
// Date: 3/27/2022

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

void readBuffer(int fd) {
    char buffer[BUFSIZ];
    ssize_t ret;

    while ((ret = read(fd, &buffer, BUFSIZ)) != 0) {
        if (ret == -1) {
            if (errno == EINTR)
                continue;

            perror("read");
            break;
        }

        printf("%s\n", buffer);
    }
}

int main() {
    int fd = open("./mileage_goals.csv", O_RDWR, 0644);

    // Truncate using ftruncate()
    int ret = ftruncate(fd, 182);

    if (ret == -1) {
        perror("ftruncate");
        return -1;
    }

    readBuffer(fd);

    if (close(fd) == -1)
        perror("close");

    // Truncate using truncate()
    ret = truncate("./mileage_goals.csv", 55);

    if (ret == -1) {
        perror("truncate");
        return -1;
    }

    fd = open("./mileage_goals.csv", O_RDONLY, 0644);

    printf("\n");
    readBuffer(fd);

    if (close(fd) == -1)
        perror("close");

    return 0;
}