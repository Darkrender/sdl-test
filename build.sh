#!/bin/sh

# We want to remove the build directory if it exists,
# then re-create it, move into it, and rebuild and compile with cmake

rm -r build
[ -d build ] || { mkdir build; [ -d build ] || exit 1; }
cd build || exit 1
cmake ..
cmake --build .