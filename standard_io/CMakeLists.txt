# C project to run the standard_io program.
# Author: Andrew Jarombek
# Date: 4/24/2022

cmake_minimum_required(VERSION 3.21)
project(standard_io C)

set(CMAKE_C_STANDARD 11)

add_executable(standard_io standard_io.c)
add_executable(stats stats.c)