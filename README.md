# system-programming-prototypes

![Maintained Label](https://img.shields.io/badge/Maintained-No-red?style=for-the-badge)
![Deprecated Label](https://img.shields.io/badge/Deprecated-Yes-lightgray?style=for-the-badge)
![Archived Label](https://img.shields.io/badge/Archived-Yes-lightgray?style=for-the-badge)

> Code Migrated to [andy-jarombek-research](https://github.com/AJarombek/andy-jarombek-research)

### Overview

System Programming code samples based on research.  The code samples are designed to be used in the CLion IDE.

### Commands

**Run CMake Locally**

```bash
mkdir out
cd out

cmake ..
cmake --build .
./system_programming_prototypes
```

**Create Base Docker Image**

```bash
docker login --username=ajarombek
docker image build -t debian-system-programming:latest .

# Push image to DockerHub with tag 'latest'
docker image tag debian-system-programming:latest ajarombek/debian-system-programming:latest
docker push ajarombek/debian-system-programming:latest
```

### Files

| Filename                | Description                                                                                                 |
|-------------------------|-------------------------------------------------------------------------------------------------------------|
| `.github`               | GitHub Actions for CI/CD pipelines.                                                                         |
| `.run`                  | Run configurations for executing code from the repository with a Jetbrains IDE (i.e. CLion).                |
| `daemon`                | Code for creating daemon processes using Linux system programming in C.                                     |
| `file_management`       | Code for file and directory management using Linux system programming in C.                                 |
| `memory_management`     | Code for memory management using Linux system programming in C.                                             |
| `memory_map`            | Code for mapping files into memory using Linux system programming in C.                                     |
| `multiplexed_io`        | Code for performing multiplexed I/O using Linux system programming in C.                                    |
| `open_file`             | Code for opening a file using Linux system programming in C.                                                |
| `physical_disk_block`   | **NOT WORKING** Code for retrieving the physical disk blocks of a file using Linux system programming in C. |
| `positional_read_write` | Code for reading and writing to a file at specific positions using Linux system programming in C.           |
| `process_management`    | Code for basic process management using Linux system programming in C.                                      |
| `pthreads`              | Code for using the pthread threading library in C.                                                          |
| `read_write`            | Code for reading and writing to a file using Linux system programming in C.                                 |
| `scatter_gather_io`     | Code for Linux Scatter/Gather I/O using Linux system programming in C.                                      |
| `standard_io`           | Code for Linux Standard I/O programmed in C.                                                                |
| `truncate`              | Code for truncating a file using Linux system programming in C.                                             |
| `Dockerfile`            | Base Dockerfile for a Linux machine with C and CMake installed.                                             |
