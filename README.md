# system-programming-prototypes

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

| Filename     | Description                                                                                  |
|--------------|----------------------------------------------------------------------------------------------|
| `.run`       | Run configurations for executing code from the repository with a Jetbrains IDE (i.e. CLion). |
| `open_file`  | Code for opening a file using Linux system programming in C.                                 |
| `Dockerfile` | Base Dockerfile for a Linux machine with C and CMake installed.                              |
