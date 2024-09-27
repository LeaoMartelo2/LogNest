#!/bin/bash

set -xe

rm latest.log usage

gcc usage.c -lLogNest -o usage


