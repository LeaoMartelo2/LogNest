#!/bin/bash
#this also serves as a install / compile test, if the install didn't work correctly this should fail! 
set -xe

rm latest.log usage

gcc usage.c -lLogNest -o usage


