// System Programming Example: Working with extended attributes for files.
// Author: Andrew Jarombek
// Date: 6/19/2022

#include <sys/types.h>
#include <sys/xattr.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    ssize_t size = listxattr("workout_plan.csv", NULL, 0);

    if (size == -1) {
        perror("listxattr");
        return 1;
    }

    // Attributes length should be zero.
    printf("Length of attributes for workout_plan.csv: %zd\n", size);

    char* value = "Andy Jarombek";
    int res = setxattr("workout_plan.csv", "user.athlete", &value, strlen(value), 0);

    if (res == -1) {
        perror("setxattr");
        return 1;
    }

    int length = getxattr("workout_plan.csv", "user.athlete", NULL, 0);

    if (length == -1) {
        perror("getxattr");
        return 1;
    }

    printf("Length of xattr 'user.athlete': %d\n", length);
    char* val = malloc(length + 1);

    if (val == NULL) {
        perror("malloc");
        return 1;
    }

    length = getxattr("workout_plan.csv", "user.athlete", val, length);

    if (length == -1) {
        perror("getxattr");
        return 1;
    }

    val[length] = '\0';
    printf("xattr value: %s\n", val);

    free(val);
}