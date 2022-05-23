# C project to run the process_management program.
# Author: Andrew Jarombek
# Date: 5/22/2022

cmake_minimum_required(VERSION 3.21)
project(read_write C)

set(CMAKE_C_STANDARD 11)

add_executable(process_management process_management.c)