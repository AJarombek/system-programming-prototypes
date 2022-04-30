// System Programming Example: Standard I/O for reading and writing binary data
// Author: Andrew Jarombek
// Date: 4/29/2022

#include <stdio.h>
#include <limits.h>

struct run {
    char* name;
    double miles;
    unsigned short hours;
    unsigned short minutes;
    unsigned short seconds;
};

int main() {
    FILE *in, *out;

    struct run log = {
        .name = "Pre Race Day Run & Strides",
        .miles = 5.67,
        .hours = 0,
        .minutes = 41,
        .seconds = 17
    };

    out = fopen("data", "w");

    if (!out) {
        perror("fopen");
        printf("Failed to open data file\n");
        return 1;
    }

    // Write the struct to a binary file
    if (!fwrite(&log, sizeof(struct run), 1, out)) {
        perror("fwrite");
        printf("Failed to write to data file\n");
        return 1;
    }

    if (fclose(out)) {
        perror("fclose");
        printf("Failed to close data file\n");
        return 1;
    }

    // Change values of the struct in memory
    log.name = "Thursday Easy + Strides";
    log.miles = 6.38;
    log.hours = 0;
    log.minutes = 44;
    log.seconds = 5;

    in = fopen("data", "r");
    if (!in) {
        perror("fopen");
        printf("Failed to open data file\n");
        return 1;
    }

    struct run log2;

    if (!fread(&log2, sizeof(struct run), 1, in)) {
        perror("fread");
        printf("Failed to read from the data file\n");
        return 1;
    }

    if (fclose(in)) {
        perror("fclose");
        printf("Failed to close data file\n");
        return 1;
    }

    printf("Log 1 Name: %s\n", log.name);
    printf("Log 2 Name: %s\n", log2.name);

    return 0;
}