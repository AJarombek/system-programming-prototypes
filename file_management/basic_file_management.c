// System Programming Example: Perform basic file management.
// Author: Andrew Jarombek
// Date: 6/14/2022

#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

void filetype(char* filename) {
    struct stat sb;
    int ret = stat(filename, &sb);

    if (ret) {
        perror("stat");
        return;
    }

    printf("%s file type: ", filename);
    switch (sb.st_mode & S_IFMT) {
        case S_IFBLK:
            printf("block device node\n");
            break;
        case S_IFCHR:
            printf("character device node\n");
            break;
        case S_IFDIR:
            printf("directory\n");
            break;
        case S_IFIFO:
            printf("fifo\n");
            break;
        case S_IFLNK:
            printf("symbolic link\n");
            break;
        case S_IFREG:
            printf("regular file\n");
            break;
        case S_IFSOCK:
            printf("socket\n");
            break;
        default:
            printf("unknown\n");
            break;
    }
}

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

    dev_t st_rdev = sb.st_rdev;
    printf("Device ID of file: %d\n", st_rdev);

    off_t st_size = sb.st_size;
    printf("Size of file in bytes: %llu\n", st_size);

    blksize_t st_blksize = sb.st_blksize;
    printf("Preferred block size for I/O on the file: %d\n", st_blksize);

    blkcnt_t st_blocks = sb.st_blocks;
    printf("Number of blocks allocated for the file: %llu\n", st_blocks);

    printf("Last access time of the file: %ld\n", sb.st_atime);
    printf("Last modification time of the file: %ld\n", sb.st_mtime);
    printf("Last status change time of the file: %ld\n", sb.st_ctime);

    // regular file
    filetype("workout_plan.csv");

    // directory
    filetype("..");

    // symbolic link
    filetype("workout");

    return 0;
}