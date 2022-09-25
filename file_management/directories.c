// System Programming Example: Working with directories.
// Author: Andrew Jarombek
// Date: 9/24/2022

#include <stdio.h>
#include <unistd.h>

int main() {
    char cwd[BUFSIZ];

    if (!getcwd(cwd, BUFSIZ)) {
        perror("getcwd");
        return -1;
    }

    printf("Current Working Directory: %s", cwd);
}