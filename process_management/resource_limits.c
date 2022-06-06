// System Programming Example: Retrieving process resource limits and setting new resource limits.
// Author: Andrew Jarombek
// Date: 6/5/2022

#include <sys/resource.h>
#include <stdio.h>

void get_limit(int resource, char* resource_name) {
    struct rlimit rlim;
    int ret = getrlimit(resource, &rlim);

    if (ret == -1) {
        perror("getrlimit");
        return;
    }

    printf("%s limits: soft=%llu, hard=%llu\n", resource_name, rlim.rlim_cur, rlim.rlim_max);
}

int main() {
    // Maximum size of a processes address space (in bytes).
    get_limit(RLIMIT_AS, "RLIMIT_AS");

    // Maximum size of a core file (in bytes).  In Linux, a core file is a snapshot of a processes address space
    // at the time it terminated abnormally.
    get_limit(RLIMIT_CORE, "RLIMIT_CORE");

    // Maximum CPU time a process can consume (in seconds).  Exceeding the hard limit will terminate the process.
    get_limit(RLIMIT_CPU, "RLIMIT_CPU");

    // Maximum size of a processes data segment and heap (in bytes).  A data segment is the memory space of
    // a program that holds global or static variables.  The heap is the memory space of a program that
    // holds dynamically allocated data.
    get_limit(RLIMIT_DATA, "RLIMIT_DATA");

    // Maximum size of a file that a process can create (in bytes).
    get_limit(RLIMIT_FSIZE, "RLIMIT_FSIZE");

    return 0;
}