# Dockerfile for running the positional_read_write program on Debian Linux
# Author: Andrew Jarombek
# Date: 3/26/2022

FROM ajarombek/debian-system-programming:latest

LABEL maintainer="andrew@jarombek.com" \
      version="1.0.0" \
      description="Dockerfile for running the read_write program on Debian Linux"

WORKDIR src
COPY . .
RUN mkdir out \
    && cp tentative_spring_races.csv out

WORKDIR out
RUN cmake ..

RUN cmake --build .

CMD ["-c", "./positional_read_write"]
ENTRYPOINT ["/bin/bash"]