# C project to run the file_management program.
# Author: Andrew Jarombek
# Date: 6/14/2022

cmake_minimum_required(VERSION 3.21)
project(open_file C)

set(CMAKE_C_STANDARD 11)

add_executable(basic_file_management basic_file_management.c)
add_executable(extended_attributes extended_attributes.c)
add_executable(directories directories.c)