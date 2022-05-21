# Dockerfile for running the physical_disk_block program on Debian Linux
# Author: Andrew Jarombek
# Date: 5/21/2022

FROM ajarombek/debian-system-programming:latest

LABEL maintainer="andrew@jarombek.com" \
      version="1.0.0" \
      description="Dockerfile for running the physical_disk_block program on Debian Linux"

WORKDIR src
COPY . .
RUN mkdir out \
    && cp spring_races.csv out

WORKDIR out
RUN cmake .. \
    && cmake --build .

CMD ["-c", "./physical_disk_block"]
ENTRYPOINT ["/bin/bash"]