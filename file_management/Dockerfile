# Dockerfile for running the file_management program on Debian Linux
# Author: Andrew Jarombek
# Date: 6/14/2022

FROM ajarombek/debian-system-programming:latest

LABEL maintainer="andrew@jarombek.com" \
      version="1.0.0" \
      description="Dockerfile for running the file_management program on Debian Linux"

WORKDIR src
COPY . .
RUN mkdir out

COPY run.sh out
COPY workout_plan.csv out

WORKDIR out
RUN cmake ..

RUN cmake --build .

CMD ["-c", ". ./run.sh"]
ENTRYPOINT ["/bin/bash"]