[ -d build ] && cmake --build ./build
[ ! -d build ] && echo "Directory /build/ DOES NOT exists. Running CMake..." && ./build.sh
./build/SDLTest