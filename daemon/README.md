### Overview

Code for creating a daemon using Linux system programming in C.

### Files

| Filename             | Description                                                                |
|----------------------|----------------------------------------------------------------------------|
| `CMakeLists.txt`     | CMake project for the `daemon.c` program.                                  |
| `Dockerfile`         | Dockerfile for running the `daemon.c` program using CMake.                 |
| `daemon.c`           | C code which creates and runs a daemon process using system calls.         |
| `daemon_shorthand.c` | C code which creates and runs a daemon process using a shorthand notation. |
| `run.sh`             | Bash script to run the C code.                                             |