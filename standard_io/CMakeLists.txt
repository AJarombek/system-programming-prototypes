# C project to run the standard_io program.
# Author: Andrew Jarombek
# Date: 4/24/2022

cmake_minimum_required(VERSION 3.21)
project(standard_io C)

set(CMAKE_C_STANDARD 11)

add_executable(reading_characters reading_characters.c)
add_executable(stats stats.c)
add_executable(writing_characters writing_characters.c)
add_executable(binary_data binary_data.c)
add_executable(file_locking file_locking.c)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
target_link_libraries(file_locking PRIVATE Threads::Threads)