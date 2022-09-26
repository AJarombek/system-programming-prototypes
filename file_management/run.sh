#!/bin/bash

# Bash script which runs the C code.
# Author: Andrew Jarombek
# Date: 6/14/2022

# Create a symbolic link & verify its creation
ln -s workout_plan.csv workout
ls -l workout

bash -c ./basic_file_management
bash -c ./extended_attributes
bash -c ./directories

touch temp.txt
echo "Temporary File" > temp.txt

bash -c ./links

# Find the symbolic links in the current directory.  Does not include hard links.
find . -maxdepth 1 -type l -ls

bash -c ./unlink