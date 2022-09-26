// System Programming Example: Working with hard links and symbolic links.
// Author: Andrew Jarombek
// Date: 9/25/2022

#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <dirent.h>

int main() {
    int ret = link("temp.txt", "temp_link");

    if (ret) {
        perror("link");
        return 1;
    }

    ret = symlink("temp.txt", "temp_symlink");

    if (ret) {
        perror("symlink");
        return 1;
    }

    printf("\nFiles in current directory including newly created hard link and symbolic link:\n");

    struct dirent *entry;
    DIR *dir = opendir(".");

    errno = 0;
    while ((entry = readdir(dir)) != NULL) {
        printf("%s\n", entry->d_name);
    }

    if (errno && !entry) {
        perror("readdir");
        return 1;
    }
}