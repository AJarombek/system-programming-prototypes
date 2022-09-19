#!/bin/bash

# Bash script which runs the C code.
# Author: Andrew Jarombek
# Date: 6/12/2022

echo "Max Kernel Thread Count: "
cat /proc/sys/kernel/threads-max

bash -c ./threading_basics
bash -c ./mutex_basics
bash -c ./thread_lifecycle