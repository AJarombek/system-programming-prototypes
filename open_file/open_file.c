// System Programming Example: Open a file
// Author: Andrew Jarombek
// Date: 12/9/2021

#include <printf.h>
#include <fcntl.h>

int main() {
    int fd = open("./temp.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

    if (fd == -1) {
        printf("Error Opening File");
        return fd;
    }

    printf("File Descriptor: %d", fd);

    return 0;
}