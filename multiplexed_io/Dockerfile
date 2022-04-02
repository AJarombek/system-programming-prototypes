# Dockerfile for running the multiplexed_io program on Debian Linux
# Author: Andrew Jarombek
# Date: 4/2/2022

FROM ajarombek/debian-system-programming:latest

LABEL maintainer="andrew@jarombek.com" \
      version="1.0.0" \
      description="Dockerfile for running the multiplexed_io program on Debian Linux"

WORKDIR src
COPY . .
RUN mkdir out

WORKDIR out
RUN cmake ..

RUN cmake --build .

CMD ["-c", "./multiplexed_io"]
ENTRYPOINT ["/bin/bash"]