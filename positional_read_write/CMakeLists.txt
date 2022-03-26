# C project to run the positional_read_write program.
# Author: Andrew Jarombek
# Date: 3/26/2022

cmake_minimum_required(VERSION 3.21)
project(read_write C)

set(CMAKE_C_STANDARD 11)

add_executable(positional_read_write positional_read_write.c)