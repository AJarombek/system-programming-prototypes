# C project to run the multiplexed_io program.
# Author: Andrew Jarombek
# Date: 4/2/2022

cmake_minimum_required(VERSION 3.21)
project(open_file C)

set(CMAKE_C_STANDARD 11)

add_executable(multiplexed_io multiplexed_io.c)
add_executable(print print.c)