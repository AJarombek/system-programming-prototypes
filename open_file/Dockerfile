# Dockerfile for running the open_file program on Debian Linux
# Author: Andrew Jarombek
# Date: 12/11/2021

FROM ajarombek/debian-system-programming:latest

LABEL maintainer="andrew@jarombek.com" \
      version="1.0.0" \
      description="Dockerfile for running the open_file program on Debian Linux"

WORKDIR src
COPY . .
RUN mkdir out

WORKDIR out
RUN cmake ..

RUN cmake --build .

CMD ["-c", "./open_file"]
ENTRYPOINT ["/bin/bash"]