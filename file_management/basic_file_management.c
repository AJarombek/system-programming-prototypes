// System Programming Example: Perform basic file management.
// Author: Andrew Jarombek
// Date: 6/14/2022

#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    struct stat sb;
    int ret = stat("workout_plan.csv", &sb);

    if (ret) {
        perror("stat");
        return 1;
    }

    dev_t st_dev = sb.st_dev;
    printf("ID of device containing file: %d\n", st_dev);

    ino_t st_ino = sb.st_ino;
    printf("File inode number: %llu\n", st_ino);

    mode_t st_mode = sb.st_mode;
    printf("Permissions for the file: %d\n", st_mode);

    nlink_t st_nlink = sb.st_nlink;
    printf("Number of hard links pointing to the file: %d\n", st_nlink);

    uid_t st_uid = sb.st_uid;
    printf("User ID of file owner: %d\n", st_uid);

    gid_t st_gid = sb.st_gid;
    printf("Group ID of file owner: %d\n", st_gid);

    return 0;
}