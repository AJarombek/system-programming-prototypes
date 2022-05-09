# C project to run the memory_map program.
# Author: Andrew Jarombek
# Date: 5/8/2022

cmake_minimum_required(VERSION 3.21)
project(open_file C)

set(CMAKE_C_STANDARD 11)

add_executable(memory_map memory_map.c)
add_executable(page_size page_size.c)