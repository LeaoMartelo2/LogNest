#!/bin/bash

set -xe 

g++ lognest.cpp -c -O2 -Wall -Wextra -fPIC -lfmt -o lognest.o


g++ -o ../libLogNest.so -shared lognest.o
