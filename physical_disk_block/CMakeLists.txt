# C project to run the physical_disk_block program.
# Author: Andrew Jarombek
# Date: 5/21/2022

cmake_minimum_required(VERSION 3.21)
project(read_write C)

set(CMAKE_C_STANDARD 11)

add_executable(physical_disk_block physical_disk_block.c)