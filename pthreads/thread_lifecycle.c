// System Programming Example: Basics of thread lifecycle actions, such as exiting threads, canceling other threads,
// and terminating the current thread.
// Author: Andrew Jarombek
// Date: 6/13/2022

#include <pthread.h>
#include <stdio.h>
#include <sys/time.h>
#include <time.h>

void* start_sleepy_thread(void *arg) {
    struct timeval sleep_tv = {.tv_sec = 1, .tv_usec = 0};

    for (int i = 0; i < 10; i++) {
        printf("Sleeping for one second.\n");
        select(0, NULL, NULL, NULL, &sleep_tv);
    }

    pthread_exit(NULL);
}

void* start_other_thread(void *arg) {
    pthread_t *other_thread = (pthread_t*) arg;

    struct timeval sleep_tv = {.tv_sec = 3, .tv_usec = 0};
    printf("Sleeping for three seconds.\n");
    select(0, NULL, NULL, NULL, &sleep_tv);

    int ret = pthread_cancel(*other_thread);

    if (ret) {
        int return_val = -1;
        perror("pthread_cancel");
        pthread_exit(&return_val);
    }

    pthread_exit(NULL);
}

int main() {
    pthread_t thread_1, thread_2;

    pthread_create(&thread_1, NULL, start_sleepy_thread, NULL);
    pthread_create(&thread_2, NULL, start_other_thread, (void*) &thread_1);

    pthread_join(thread_1, NULL);
    pthread_join(thread_2, NULL);

    return 0;
}