// System Programming Example: Alignment of allocated memory
// Author: Andrew Jarombek
// Date: 9/18/2022

#define _GNU_SOURCE

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

struct Run {
    char* date;
    double miles;
};

int main() {
    char *buf;

    // Allocate 1024 bytes of memory aligned at a multiple of 8.
    int ret = posix_memalign(&buf, 8, 1024);

    if (ret) {
        perror("posix_memalign");
        return -1;
    }

    struct Run *injuryRun;

    // Allocate memory aligned along a page boundary (the page size on my machine is 4096 bytes)
    // NOTE: valloc() is no longer suggested for use.
    injuryRun = valloc(sizeof(struct Run));

    if (!injuryRun) {
        perror("valloc");
        return -1;
    }

    injuryRun->date = "9/18/2022";
    injuryRun->miles = 1.6;

    free(buf);
    free(injuryRun);

    int pageSize = getpagesize();
    printf("Current page size: %d\n", pageSize);

    int voidPtrSize = sizeof(void *);
    printf("Void pointer size: %d\n", voidPtrSize);

    return 0;
}