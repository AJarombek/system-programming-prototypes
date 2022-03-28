// System Programming Example: Read and Write to a file at specific positions
// Author: Andrew Jarombek
// Date: 3/26/2022

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

off_t seek(int fd, int seek_position) {
    off_t ret = lseek(fd, (off_t) seek_position, SEEK_SET);

    if (ret == (off_t) -1) {
        printf("Error occurred seeking to position %d\n", seek_position);
    }

    return ret;
}

int main() {
    int fd = open("./tentative_spring_races.csv", O_RDWR, 0644);

    // Seek to the last two races
    off_t ret = seek(fd, 218);

    if (ret == (off_t) -1) {
        return -1;
    }

    // Print only June races (last two races)
    readBuffer(fd);
    printf("\n");

    // Seek to the race entry to replace
    ret = seek(fd, 201);

    if (ret == (off_t) -1) {
        return -1;
    }

    // Replace a race entry with another potential race
    const char *buf = "NYRR Brooklyn Half Marathon,Road,Half Marathon,5/21/2022         ";
    ssize_t r;

    while ((r = write(fd, buf, strlen(buf))) != 0) {
        if (r == -1) {
            if (errno == EINTR)
                continue;

            perror("write");
            break;
        }

        buf += r;
    }

    // Seek to the start of the file
    ret = seek(fd, 0);

    if (ret == (off_t) -1) {
        return -1;
    }

    // Print all the races
    readBuffer(fd);
    printf("\n");

    // Seek to the end of the file
    ret = lseek(fd, (off_t) 0, SEEK_END);

    if (ret == (off_t) -1) {
        return -1;
    }

    // Add another potential race using write()
    buf = "\nNYRR Team Championships,Road,5 Mile,7/31/2022";

    while ((r = write(fd, buf, strlen(buf))) != 0) {
        if (r == -1) {
            if (errno == EINTR)
                continue;

            perror("write");
            break;
        }

        buf += r;
    }

    // Add another potential race at a specific position using pwrite()
    buf = "\nNYRR Brooklyn R-U-N 5K,Road,5K,7/18/2022                    ";

    while ((r = pwrite(fd, buf, strlen(buf), 300)) != 0) {
        if (r == -1) {
            if (errno == EINTR)
                continue;

            perror("write");
            break;
        }

        buf += r;
    }

    // Seek to the start of the file
    ret = seek(fd, 0);

    if (ret == (off_t) -1) {
        return -1;
    }

    // Print all the races
    readBuffer(fd);

    if (close(fd) == -1)
        perror("close");

    return 0;
}