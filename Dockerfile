# Dockerfile for system programming on Debian Linux
# Author: Andrew Jarombek
# Date: 12/10/2021

FROM debian:11

LABEL maintainer="andrew@jarombek.com" \
      version="1.0.0" \
      description="Dockerfile for system programming on Debian Linux"

# Install C, C++, and CMake
RUN apt-get -y update \
    && apt-get -y install build-essential wget libssl-dev \
    && wget https://github.com/Kitware/CMake/releases/download/v3.21.0/cmake-3.21.0.tar.gz \
    && tar -zxvf cmake-3.21.0.tar.gz

WORKDIR cmake-3.21.0
RUN ./bootstrap \
    && make \
    && make install