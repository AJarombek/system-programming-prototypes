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

COPY mileage_goals.csv out
COPY run.sh out

WORKDIR out
RUN cmake ..

RUN cmake --build .

CMD ["-c", ". ./run.sh"]
ENTRYPOINT ["/bin/bash"]