# C project to run the threading_basics program.
# Author: Andrew Jarombek
# Date: 6/11/2022

cmake_minimum_required(VERSION 3.21)
project(standard_io C)

set(CMAKE_C_STANDARD 11)

add_executable(threading_basics threading_basics.c)
add_executable(mutex_basics mutex_basics.c)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

target_link_libraries(threading_basics PRIVATE Threads::Threads)
target_link_libraries(mutex_basics PRIVATE Threads::Threads)