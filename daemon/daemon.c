// System Programming Example: Creating a daemon using multiple system calls
// Author: Andrew Jarombek
// Date: 5/29/2022

#include <sys/resource.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main() {
    // Named after daemons in ancient greek mythology, who performed tasks for the gods
    // or were sometimes thought of as guardian angels.
    // Similarly, Linux daemons perform tasks for foreground processes.
    // https://en.wikipedia.org/wiki/Daemon_(computing)

    // Step 1: Create a new process which will become the daemon.
    pid_t pid = fork();

    if (pid == -1) {
        return -1;
    } else if (pid != 0) {
        // Step 2: Call exit() in the parent process.
        exit(EXIT_SUCCESS);
    }

    // Step 3: Give the daemon a new process group and session.
    if (setsid() == -1) {
        return -1;
    }

    // Step 4: Set the working directory to the root filesystem directory.
    if (chdir("/") == -1) {
        return -1;
    }

    // Step 5: Close all open files.
    struct rlimit rlim;
    getrlimit(RLIMIT_NOFILE, &rlim);

    for (int i = 0; i < rlim.rlim_max; i++) {
        close(i);
    }

    // Step 6: Redirect stdin, stdout, and stderr to /dev/null.
    open("/dev/null", O_RDWR);
    dup(0);
    dup(0);

    // Step 7: Run the daemon.
    for (;;) {
        int fd = creat("/dotty.log", 0644);
        char* message = "Dotty is a wonderful horse, and does her best to comfort and bring warmth to those I love.\n";

        int ret = write(fd, message, strlen(message));

        if (ret == -1) {
            return -1;
        }

        // Sleep for 10 seconds
        struct timeval sleep_tv = {.tv_sec = 10, .tv_usec = 0};
        select(0, NULL, NULL, NULL, &sleep_tv);
    }

    return 0;
}