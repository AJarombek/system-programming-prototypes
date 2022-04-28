// System Programming Example: Standard I/O for writing characters
// Author: Andrew Jarombek
// Date: 4/27/2022

#include <stdio.h>
#include <limits.h>

int main() {
    FILE *stream;

    stream = fopen("prs.csv", "a");

    if (fputc('\n', stream) == EOF)
        printf("Failed to write a newline character to prs.csv\n");

    if (fputc('O', stream) == EOF)
        printf("Failed to write a character to prs.csv\n");

    if (fputs("utdoor Track,1500m,4:08,4:26\n", stream) == EOF)
        printf("Failed to write an outdoor track entry to prs.csv\n");

    if (fputs("Indoor Track,1500m,4:21,4:41\n", stream) == EOF)
        printf("Failed to write an outdoor track entry to prs.csv\n");

    if (fclose(stream) == EOF)
        printf("Failed to close prs.csv\n");

    stream = fopen("prs.csv", "r");

    // Read all the lines in the stream one at a time
    char buf[LINE_MAX];
    int index = 1;
    while (fgets(buf, LINE_MAX, stream)) {
        printf("\nLine %d\n", index);
        printf("%s", buf);
        index++;
    }

    if (fclose(stream) == EOF)
        printf("Failed to close prs.csv\n");
}