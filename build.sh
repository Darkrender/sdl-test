rm -r build
[ -d build ] || { mkdir build; [ -d build ] || exit 1; }
cd build || exit 1
cmake ..
cmake --build .