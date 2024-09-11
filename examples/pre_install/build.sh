#!/bin/bash
 
set -xe

rm latest.log

g++ pre_install.cpp -Wall -Wextra -O2 -lfmt -L../../src/ -lLogNest -Wl,-rpath,../../src/ -o pre_install
