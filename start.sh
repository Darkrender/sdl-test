#!/bin/sh

# If build directory doesn't exist, run the build.sh script which will create it and run some cmake commands
[ ! -d build ] && echo "Directory /build/ DOES NOT exists. Running CMake..." && ./build.sh

# If the build folder does exist, navigate into it and recompile with cmake
[ -d build ] && cd build && cmake --build .

# The final executable file will be in a different location depending on platform
# On mac, it will just end up in the root of the build folder...
if [ -e SDLTest ]
then
    ./SDLTest

# On windows, it will typically end up in build/Debug/<ProjectName>.exe
# unless we specifically make a release build
elif [ -e Debug/SDLTest.exe ]
then
    ./Debug/SDLTest.exe
else
    echo "Couldn't find executable to run. Check the build folder for the path to the executable..."
fi