#!/bin/bash

set -xe

rm latest.log

g++ installed.cpp -lfmt -lLogNest -o installed


