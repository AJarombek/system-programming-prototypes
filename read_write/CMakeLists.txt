# C project to run the read_write program.
# Author: Andrew Jarombek
# Date: 2/23/2022

cmake_minimum_required(VERSION 3.21)
project(read_write C)

set(CMAKE_C_STANDARD 11)

add_executable(read_write read_write.c)