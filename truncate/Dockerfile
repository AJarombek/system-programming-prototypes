# Dockerfile for running the truncate program on Debian Linux
# Author: Andrew Jarombek
# Date: 3/27/2022

FROM ajarombek/debian-system-programming:latest

LABEL maintainer="andrew@jarombek.com" \
      version="1.0.0" \
      description="Dockerfile for running the truncate program on Debian Linux"

WORKDIR src
COPY . .
RUN mkdir out \
    && cp mileage_goals.csv out

WORKDIR out
RUN cmake ..

RUN cmake --build .

CMD ["-c", "./truncate"]
ENTRYPOINT ["/bin/bash"]