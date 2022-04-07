cmake_minimum_required(VERSION 3.23)

project(SDLTest)

add_executable(${PROJECT_NAME} src/main.cpp)

add_subdirectory(libs/SDL2)
target_include_directories(${PROJECT_NAME} PUBLIC libs/SDL2/include)
target_link_directories(${PROJECT_NAME} PRIVATE libs/SDL2)
target_link_libraries(${PROJECT_NAME} SDL2)