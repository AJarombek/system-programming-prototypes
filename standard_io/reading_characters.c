// System Programming Example: Standard I/O for reading characters
// Author: Andrew Jarombek
// Date: 4/24/2022

#include <stdio.h>
#include <limits.h>
#include <errno.h>

int main() {
    FILE *stream;

    stream = fopen("prs.csv", "r");

    if (!stream)
        printf("Failed to open file prs.csv\n");

    // Read the first character from the stream
    int c = fgetc(stream);

    if (c == EOF) {
        printf("prs.csv stream unexpectedly empty\n");
    } else {
        printf("First character in prs.csv: %c\n", (char) c);
    }

    // Place the first character back on the stream
    ungetc(c, stream);

    // Read all the lines in the stream one at a time
    char buf[LINE_MAX];
    int index = 1;
    while (fgets(buf, LINE_MAX, stream)) {
        printf("\nLine %d\n", index);
        printf("%s", buf);
        index++;
    }

    // Seek from the start of the stream
    int res = fseek(stream, 54, SEEK_SET);

    if (res == -1) {
        printf("Failed to seek in stream\n");
    } else {
        printf("\n\nLast Line\n");

        if (fgets(buf, LINE_MAX, stream)) {
            printf("%s", buf);
        }
    }

    // First seek from the beginning of the stream, and then seek from the current position
    fseek(stream, 54, SEEK_SET);
    fseek(stream, 17, SEEK_CUR);

    printf("\n\nLast Pace\n");

    if (fgets(buf, LINE_MAX, stream)) {
        printf("%s", buf);
    }

    // Seek backwards from the end of the stream
    fseek(stream, -9, SEEK_END);

    printf("\n\nLast Time and Pace\n");

    if (fgets(buf, LINE_MAX, stream)) {
        printf("%s", buf);
    }

    // Rewind the stream back to the start [same as fseek(stream, 0, SEEK_SET)]
    errno = 0;
    rewind(stream);

    if (errno) {
        printf("\nError occurred while rewinding the stream.\n");
    } else {
        printf("\n\nHeader Line\n");

        if (fgets(buf, LINE_MAX, stream)) {
            printf("%s", buf);
        }
    }

    if (fclose(stream) == EOF)
        printf("Failed to close prs.csv\n");
}