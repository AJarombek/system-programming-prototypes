// System Programming Example: Perform basic process management
// Author: Andrew Jarombek
// Date: 5/22/2022

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    pid_t pid = getgid();
    printf("The current process id is: %d", pid);
}