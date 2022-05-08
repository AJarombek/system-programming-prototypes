# Dockerfile for running the scatter_gather_io program on Debian Linux
# Author: Andrew Jarombek
# Date: 4/24/2022

FROM ajarombek/debian-system-programming:latest

LABEL maintainer="andrew@jarombek.com" \
      version="1.0.0" \
      description="Dockerfile for running the scatter_gather_io program on Debian Linux"

WORKDIR src
COPY . .
RUN mkdir out

WORKDIR out
RUN cmake .. \
    && cmake --build .

CMD ["-c", "./scatter_gather_io"]
ENTRYPOINT ["/bin/bash"]