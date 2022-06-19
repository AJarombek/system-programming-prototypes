#!/bin/bash

# Bash script which runs the C code.
# Author: Andrew Jarombek
# Date: 6/14/2022

# Create a symbolic link & verify its creation
ln -s workout_plan.csv workout
ls -l workout

bash -c ./basic_file_management