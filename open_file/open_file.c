// System Programming Example: Open a file
// Author: Andrew Jarombek
// Date: 12/9/2021

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd = open("./temp.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

    if (fd == -1) {
        printf("Error Opening File temp.txt \n");
        return fd;
    }

    printf("File Descriptor temp.txt: %d \n", fd);

    // Shorthand for the above open() system call.
    fd = creat("./temp2.txt", 0644);

    if (fd == -1) {
        printf("Error Opening File temp2.txt \n");
        return fd;
    }

    printf("File Descriptor temp2.txt: %d \n", fd);

    if (close(fd) == -1)
        perror("close");

    return 0;
}