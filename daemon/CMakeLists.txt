# C project to run the daemon program.
# Author: Andrew Jarombek
# Date: 5/29/2022

cmake_minimum_required(VERSION 3.21)
project(read_write C)

set(CMAKE_C_STANDARD 11)

add_executable(daemon daemon.c)