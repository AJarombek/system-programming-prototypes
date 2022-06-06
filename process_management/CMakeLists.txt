# C project to run the process_management program.
# Author: Andrew Jarombek
# Date: 5/22/2022

cmake_minimum_required(VERSION 3.21)
project(read_write C)

set(CMAKE_C_STANDARD 11)

add_executable(process_management process_management.c)
add_executable(sessions sessions.c)
add_executable(system system.c)
add_executable(waitpid waitpid.c)
add_executable(yield yield.c)
add_executable(priority priority.c)
add_executable(resource_limits resource_limits.c)