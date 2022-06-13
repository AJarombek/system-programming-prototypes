// System Programming Example: Basics of the pthread library.
// Author: Andrew Jarombek
// Date: 6/11/2022

#include <pthread.h>
#include <stdio.h>

struct exercise_run {
    char* date;
    char* time;
    double miles;
};

void* start_thread(void *arg) {
    struct exercise_run *run = (struct exercise_run*) arg;
    printf("Ran %.2f miles in %s on %s.\n", run->miles, run->time, run->date);
    return NULL;
}

int main() {
    pthread_t thread_1, thread_2;

    struct exercise_run run1 = {.date = "June 11th, 2022", .time = "49:03", .miles = 6.55};
    struct exercise_run run2 = {.date = "June 12th, 2022", .time = "1:08:32", .miles = 8.97};

    pthread_create(&thread_1, NULL, start_thread, (void*) &run1);
    pthread_create(&thread_2, NULL, start_thread, (void*) &run2);

    pthread_join(thread_1, NULL);
    pthread_join(thread_2, NULL);

    return 0;
}