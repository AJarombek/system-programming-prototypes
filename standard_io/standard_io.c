// System Programming Example: Standard I/O
// Author: Andrew Jarombek
// Date: 4/24/2022

#include <stdio.h>
#include <limits.h>

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

    fclose(stream);
}