# C project to run the scatter_gather_io program.
# Author: Andrew Jarombek
# Date: 4/24/2022

cmake_minimum_required(VERSION 3.21)
project(standard_io C)

set(CMAKE_C_STANDARD 11)

add_executable(scatter_gather_io scatter_gather.c)