// System Programming Example: Retrieve the physical disk blocks of a file
// Author: Andrew Jarombek
// Date: 5/21/2022

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <linux/fs.h>

int main() {
    int fd = open("./spring_races.csv", O_RDONLY);

    if (fd == -1) {
        perror("open");
        return fd;
    }

    struct stat buf;
    int ret = fstat(fd, &buf);

    if (ret < 0) {
        perror("fstat");
        return ret;
    }

    int blocks = buf.st_blocks;

    if (blocks < 0) {
        printf("Failed to get block size");
        return -1;
    } else if (blocks == 0) {
        printf("No blocks allocated");
        return -1;
    }

    printf("%d blocks allocated for file spring_races.csv", blocks);

    for (int i = 0; i < blocks; i++) {
        int physical_block = ioctl(fd, FIBMAP, &i);

        if (physical_block < 0) {
            perror("ioctl");
            return -1;
        }

        printf("Physical Block: %d, Physical Block: %d", i, physical_block);
    }

    if (close(fd) == -1)
        perror("close");

    return 0;
}