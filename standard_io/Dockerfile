# Dockerfile for running the standard_io program on Debian Linux
# Author: Andrew Jarombek
# Date: 4/24/2022

FROM ajarombek/debian-system-programming:latest

LABEL maintainer="andrew@jarombek.com" \
      version="1.0.0" \
      description="Dockerfile for running the standard_io program on Debian Linux"

WORKDIR src
COPY . .
RUN mkdir out

COPY prs.csv out
WORKDIR out
RUN cmake ..

RUN cmake --build .

CMD ["-c", "./standard_io"]
ENTRYPOINT ["/bin/bash"]