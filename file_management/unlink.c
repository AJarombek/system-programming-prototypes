// System Programming Example: Unliking and removing files.
// Author: Andrew Jarombek
// Date: 9/25/2022

#include <unistd.h>
#include <stdio.h>

int main() {
    // Remove a symbolic link using unlink()
    int ret = unlink("temp_symlink");

    if (ret) {
        perror("unlink");
        return 1;
    }

    // Remove a hard link using remove()
    ret = remove("temp_link");

    if (ret) {
        perror("remove");
        return 1;
    }

    // Linux has no system call for copying a file in a single step.
    // However, it does have a system call for renaming a file.
    ret = rename("temp.txt", "new.txt");

    if (ret) {
        perror("rename");
        return 1;
    }
}