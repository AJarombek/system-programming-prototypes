# C project to run the memory_management program.
# Author: Andrew Jarombek
# Date: 9/18/2022

cmake_minimum_required(VERSION 3.21)
project(open_file C)

set(CMAKE_C_STANDARD 11)

add_executable(alignment alignment.c)