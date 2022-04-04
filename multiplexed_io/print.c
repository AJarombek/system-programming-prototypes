// System Programming Example: Perform Multiplexed I/O
// Author: Andrew Jarombek
// Date: 4/2/2022

#include <stdio.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>
#include <string.h>

#define TIMEOUT 5

char* get_time() {
    time_t raw_time;
    struct tm *time_info;

    time(&raw_time);
    time_info = localtime(&raw_time);
    return asctime(time_info);
}

int main() {
    int i = 0;

    while (i < 30) {
        struct timeval sleep_tv = {.tv_sec = 2, .tv_usec = 0};
        select(0, NULL, NULL, NULL, &sleep_tv);

        char* time = get_time();
        write(STDIN_FILENO, time, strlen(time));
        close(STDIN_FILENO);

        i++;
    }

    return 0;
}