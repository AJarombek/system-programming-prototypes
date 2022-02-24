# Dockerfile for running the read_write program on Debian Linux
# Author: Andrew Jarombek
# Date: 2/23/2022

FROM ajarombek/debian-system-programming:latest

LABEL maintainer="andrew@jarombek.com" \
      version="1.0.0" \
      description="Dockerfile for running the read_write program on Debian Linux"

WORKDIR src
COPY . .
RUN mkdir out \
    && cp upcoming_races.csv out

WORKDIR out
RUN cmake ..

RUN cmake --build .

CMD ["-c", "./read_write"]
ENTRYPOINT ["/bin/bash"]