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

    // Maximum number of file locks that a process can hold.
    get_limit(RLIMIT_LOCKS, "RLIMIT_LOCKS");

    // Maximum amount of memory that a process can lock (in bytes).
    get_limit(RLIMIT_MEMLOCK, "RLIMIT_MEMLOCK");

    // Maximum bytes a user can allocate to POSIX message queues.  POSIX message queues are a way for processes
    // to exchange data via messages.
    get_limit(RLIMIT_MSGQUEUE, "RLIMIT_MSGQUEUE");

    // Maximum value that a process can lower its nice value (increase its priority).
    get_limit(RLIMIT_NICE, "RLIMIT_NICE");

    // One greater than the maximum number of file descriptors that a process can hold open.
    get_limit(RLIMIT_NOFILE, "RLIMIT_NOFILE");

    // Maximum number of processes that a user can have open simultaneously.
    get_limit(RLIMIT_NPROC, "RLIMIT_NPROC");

    // Maximum number of pages that a process can have open in memory (resident size, RSS).
    get_limit(RLIMIT_RSS, "RLIMIT_RSS");

    // Maximum CPU time that a real-time process can consume without issuing a blocking call.  A blocking call
    // is a system call that suspends the current process (makes it wait or go to sleep) until an event occurs
    // that unblocks it.
    get_limit(RLIMIT_RTTIME, "RLIMIT_RTTIME");

    // Maximum real-time priority that a process can request.  This is different from the nice value, and
    // applies specifically to real-time processes.
    get_limit(RLIMIT_RTPRIO, "RLIMIT_RTPRIO");

    // Maximum number of signals that can be queued by a user.  Despite this limit, it is always possible to queue an
    // instance of a non-yet queued signal.
    get_limit(RLIMIT_SIGPENDING, "RLIMIT_SIGPENDING");

    // Maximum size of the stack for a process.
    get_limit(RLIMIT_STACK, "RLIMIT_STACK");

    // Set a new limit for the number of file locks a process can hold.
    struct rlimit rlim;
    rlim.rlim_cur = 1024;
    rlim.rlim_max = RLIM_INFINITY;

    int ret = setrlimit(RLIMIT_LOCKS, &rlim);

    if (ret == -1) {
        perror("setrlimit");
        return 1;
    }

    // Get the newly changed file locks limit.
    get_limit(RLIMIT_LOCKS, "**NEW** RLIMIT_LOCKS");

    return 0;
}