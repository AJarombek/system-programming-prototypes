// System Programming Example: Standard I/O
// Author: Andrew Jarombek
// Date: 4/24/2022

#include <stdio.h>
#include <sys/stat.h>

int main() {
    struct stat sfile;
    stat("prs.csv", &sfile);
    printf("Block Size: %d\n", sfile.st_blksize);
}