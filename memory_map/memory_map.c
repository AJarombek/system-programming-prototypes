// System Programming Example: Mapping files into memory
// Author: Andrew Jarombek
// Date: 5/8/2022

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/mman.h>

int main() {
    char* filename = "./week_plan.csv";
    int fd = open(filename, O_RDONLY);

    if (fd == -1) {
        perror("open");
        return 1;
    }

    struct stat sb;
    if (fstat(fd, &sb) == -1) {
        perror("fstat");
        return 1;
    }

    if (!S_ISREG(sb.st_mode)) {
        fprintf(stderr, "%s is not a file.\n", filename);
        return 1;
    }

    // Map the file to memory.
    char *p = mmap(0, sb.st_size, PROT_READ, MAP_SHARED, fd, 0);
    if (p == MAP_FAILED) {
        perror("mmap");
        return 1;
    }

    // The file is now mapped in memory, it is ok to close the file descriptor.
    if (close(fd) == -1) {
        perror("close");
        return 1;
    }

    // Advise the kernel that the data is read sequentially, thus enabling readahead.
    // This is an optimization and not necessary for a basic example like this.
    int ret = madvise(p, sb.st_size, MADV_SEQUENTIAL);

    if (ret < 0) {
        perror("madvice");
    }

    printf("Printing the file mapped in memory:\n");
    for (off_t len = 0; len < sb.st_size; len++) {
        putchar(p[len]);
    }

    // Unmap the file from memory
    if (munmap(p, sb.st_size) == -1) {
        perror("munmap");
        return 1;
    }

    return 0;
}