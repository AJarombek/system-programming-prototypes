// System Programming Example: Dealing with sessions, process groups, groups, and users.
// Author: Andrew Jarombek
// Date: 5/30/2022

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    // Session: Collection of one or more process groups.
    // Sessions usually correlate to an open shell session.
    pid_t session_id = getsid(0);

    if (session_id == -1) {
        perror("getsid");
        return -1;
    }

    printf("Current session id: %d\n", session_id);

    // Process Group: A collection of one or more processes.  These processes are
    // generally associated with one another and the process group is a form of job control.
    pid_t pg_id = getpgid(0);

    if (pg_id == -1) {
        perror("getpgid");
        return -1;
    }

    printf("Current process group id: %d\n", pg_id);

    // Process: A running program.  Programs include a binary image loaded into memory, kernel resources,
    // virtualized memory, a security context, one or more threads, and more.
    pid_t pid = getpid();
    printf("Current process id: %d\n", pid);

    // Group: A collection of users with set privileges.
    gid_t gid = getgid();
    printf("Current group id: %d\n", gid);

    // User: An entity that can perform operations in Linux.
    uid_t uid = getuid();
    printf("Current user id: %d\n", uid);

    return 0;
}