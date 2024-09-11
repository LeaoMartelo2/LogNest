#!/bin/bash
 
set -xe

g++ main.cpp -Wall -Wextra -O2 -lfmt -L../build/ -lLogNest -Wl,-rpath,../build/ -o main
