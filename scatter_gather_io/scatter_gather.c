// System Programming Example: Standard I/O for manually locking files
// Author: Andrew Jarombek
// Date: 5/6/2022

#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/uio.h>

int main() {
    struct iovec iov[6];

    char *buf[] = {
        "type,name,location,distance,date,registered\n",
        "Outdoor Track,Tracksmith Community Mile,New York, NY,1 Mile,5/20/2022,Yes\n",
        "Outdoor Track,Battle Road Twilight Meet,Waltham, MA,1500m,6/4/2022,No\n",
        "Road,NYRR Queens 10K,New York, NY,10K,6/18/2022,Yes\n",
        "Outdoor Track,GSTC Track Club Championships,Edison, NJ,800m,6/24/2022,No\n",
        "Outdoor Track,USATF Club Championships,West Long Branch, NJ,5000m,7/2/2022,No\n"
    };

    int fd = open("race_plan.csv", O_WRONLY | O_CREAT | O_TRUNC);

    if (fd == -1) {
        perror("open");
        return 1;
    }

    for (int i = 0; i < 6; i++) {
        iov[i].iov_base = buf[i];
        iov[i].iov_len = strlen(buf[i]) + 1;
    }

    ssize_t nr = writev(fd, iov, 6);

    if (nr == -1) {
        perror("writev");
        return 1;
    }

    printf("Wrote %zd bytes using Scatter/Gather I/O\n", nr);

    if (close(fd) == -1) {
        perror("close");
        return 1;
    }

    fd = open("race_plan.csv", O_RDONLY);

    if (fd == -1) {
        perror("open");
        return 1;
    }

    char header[strlen(buf[0]) + 1], nextRace[strlen(buf[1]) + 1], potentialRace[strlen(buf[2]) + 1];
    char nextNYCRace[strlen(buf[3]) + 1], potentialRace2[strlen(buf[4]) + 1], potentialRace3[strlen(buf[5]) + 1];
    struct iovec io[6];

    io[0].iov_base = header;
    io[0].iov_len = sizeof(header);
    io[1].iov_base = nextRace;
    io[1].iov_len = sizeof(nextRace);
    io[2].iov_base = potentialRace;
    io[2].iov_len = sizeof(potentialRace);
    io[3].iov_base = nextNYCRace;
    io[3].iov_len = sizeof(nextNYCRace);
    io[4].iov_base = potentialRace2;
    io[4].iov_len = sizeof(potentialRace2);
    io[5].iov_base = potentialRace3;
    io[5].iov_len = sizeof(potentialRace3);

    nr = readv(fd, io, 6);

    if (nr == -1) {
        perror("readv");
        return 1;
    }

    for (int i = 0; i < 6; i++) {
        printf("%d: %s", i, (char*) io[i].iov_base);
    }

    if (close(fd) == -1) {
        perror("close");
        return 1;
    }

    return 0;
}