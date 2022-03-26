// System Programming Example: Read and Write to a file at specific positions
// Author: Andrew Jarombek
// Date: 3/26/2022

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

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

        printf("%s\n", buffer);
        index++;
    }
}

int main() {
    int fd = open("./tentative_spring_races.csv", O_RDWR, 0644);

    // Seek to the last two races
    int seek_position = 201;
    off_t ret = lseek(fd, (off_t) seek_position, SEEK_SET);

    if (ret == (off_t) -1) {
        printf("Error occurred seeking to position %d\n", seek_position);
        return -1;
    }

    // Print only June races (last two races)
    readBuffer(fd);
}