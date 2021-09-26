#!/bin/sh
dir=build
cmake --build $dir --clean-first
ctest --test-dir $dir
