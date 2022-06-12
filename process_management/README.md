### Overview

Code for basic process management using Linux system programming in C.

### Files

| Filename               | Description                                                            |
|------------------------|------------------------------------------------------------------------|
| `CMakeLists.txt`       | CMake project for the `process_management.c` program.                  |
| `Dockerfile`           | Dockerfile for running the `process_management.c` program using CMake. |
| `priority.c`           | C code which gets and sets the nice value of a process.                |
| `process_management.c` | C code which performs basic process management.                        |
| `processor_affinity.c` | C code which performs processor (CPU) affinity.                        |
| `resource_limits.c`    | C code which gets and sets the resource limits of a process.           |
| `run.sh`               | Bash script to run the C code.                                         |
| `scheduling_policy.c`  | C code for checking the scheduling policy of a process.                |
| `sessions.c`           | C code dealing with sessions, process groups, groups, and users.       |
| `system.c`             | C code which performs a `system()` system call to run a Bash command.  |
| `waitpid.c`            | C code which performs a `waitpid()` system call.                       |
| `yield.c`              | C code which yields to the process scheduler.                          |