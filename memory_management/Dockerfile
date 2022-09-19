# Dockerfile for running the memory_management program on Debian Linux
# Author: Andrew Jarombek
# Date: 9/18/2022

FROM ajarombek/debian-system-programming:latest

LABEL maintainer="andrew@jarombek.com" \
      version="1.0.0" \
      description="Dockerfile for running the memory_management program on Debian Linux"

WORKDIR src
COPY . .
RUN mkdir out

COPY run.sh out

WORKDIR out
RUN cmake .. \
    && cmake --build .

CMD ["-c", ". ./run.sh"]
ENTRYPOINT ["/bin/bash"]