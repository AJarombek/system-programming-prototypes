// System Programming Example: Standard I/O for manually locking files
// Author: Andrew Jarombek
// Date: 5/6/2022

#include <stdio.h>
#include <fcntl.h>
#include <sys/uio.h>

int main() {
    struct iovec iov[3];
    ssize_t nr;
    int i;

    char *buf[] = {
        "type,name,location,distance,date\n",
        "Outdoor Track,Tracksmith Community Mile,New York, NY,1 Mile,5/20/2022\n",
        "Outdoor Track,Battle Road Twilight Meet,Waltham, MA,1500m,6/4/2022\n\n"
    };

    int fd = open("race_plan.csv", O_WRONLY | O_CREAT | O_TRUNC);

    if (fd == -1) {
        perror("open");
        return 1;
    }
}