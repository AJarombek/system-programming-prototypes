#!/bin/bash

# Bash script which runs the C code.
# Author: Andrew Jarombek
# Date: 4/23/2022

# Since no file is redirected to stdin, the call to select() times out
bash -c ./multiplexed_io

# Since a file is redirected to stdin, select() returns without timing out
bash -c ./multiplexed_io < mileage_goals.csv

# Since no file is redirected to stdin, the call to poll() times out
bash -c ./poll

# Since a file is redirected to stdin, poll() returns without timing out
bash -c ./poll < mileage_goals.csv