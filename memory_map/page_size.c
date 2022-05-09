// System Programming Example: Retrieving the page size at runtime
// Author: Andrew Jarombek
// Date: 5/8/2022

#include <unistd.h>
#include <stdio.h>

int main() {
    long page_size = sysconf(_SC_PAGESIZE);
    printf("Current page size: %ld\n", page_size);

    int page_size_linux = getpagesize();
    printf("Confirming current page size: %d\n", page_size_linux);
}