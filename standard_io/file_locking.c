// System Programming Example: Standard I/O for manually locking files
// Author: Andrew Jarombek
// Date: 5/6/2022

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <limits.h>

void* thread_one_exec(void *vargp) {
    FILE *stream = (FILE*) vargp;
    flockfile(stream);
    sleep(2);

    fputs("Indoor Track,3000m,9:03,4:51\n", stream);
    fflush(stream);

    funlockfile(stream);
    return NULL;
}

void* thread_two_exec(void *vargp) {
    FILE *stream = (FILE*) vargp;
    flockfile(stream);

    fputs("Outdoor Track,3000m,9:22,5:01\n", stream);
    fflush(stream);

    funlockfile(stream);
    return NULL;
}

int main() {
    FILE *stream;
    stream = fopen("prs.csv", "r");

    pthread_t thread_one;
    pthread_create(&thread_one, NULL, thread_one_exec, (void*) stream);

    pthread_t thread_two;
    pthread_create(&thread_two, NULL, thread_two_exec, (void*) stream);

    pthread_join(thread_one, NULL);
    pthread_join(thread_two, NULL);

    fclose(stream);
    stream = fopen("prs.csv", "r");

    char buf[LINE_MAX];
    int index = 1;
    while (fgets(buf, LINE_MAX, stream)) {
        printf("%s", buf);
        index++;
    }

    return 0;
}