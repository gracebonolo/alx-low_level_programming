#!/bin/bash

# Compile each .c file into object files
gcc -c *.c

# Create the static library from the object files
ar rcs liball.a *.o

# Clean up the object files
rm *.o

