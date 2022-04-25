### Overview

Code for performing multiplexed I/O using Linux system programming in C.

### Files

| Filename            | Description                                                        |
|---------------------|--------------------------------------------------------------------|
| `CMakeLists.txt`    | CMake project for the `multiplexed_io.c` program.                  |
| `Dockerfile`        | Dockerfile for running the `multiplexed_io.c` program using CMake. |
| `multiplexed_io.c`  | C code which performs multiplexed I/O using `select()`.            |
| `poll.c`            | C code which performs multiplexed I/O using `poll()`.              |
| `mileage_goals.csv` | File to use in multiplexed I/O.                                    |
| `run.sh`            | Bash script to run the C code.                                     |