#!/bin/bash
 
set -xe

g++ main.cpp -Wall -Wextra -O2 -lfmt -L../ -lLogNest -Wl,-rpath,../ -o main
