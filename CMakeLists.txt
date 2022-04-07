cmake_minimum_required(VERSION 3.23)

project(SDLTest)

add_executable(${PROJECT_NAME} src/main.cpp)

# DOWNLOAD ALL THE SUBMODULES
find_package(Git QUIET)
if(GIT_FOUND AND EXISTS "${PROJECT_SOURCE_DIR}/.git")
# Update submodules as needed
    option(GIT_SUBMODULE "Check submodules during build" ON)
    if(GIT_SUBMODULE)
        message(STATUS "Submodule update")
        execute_process(COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive
                        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
                        RESULT_VARIABLE GIT_SUBMOD_RESULT)
        if(NOT GIT_SUBMOD_RESULT EQUAL "0")
            message(FATAL_ERROR "git submodule update --init failed with ${GIT_SUBMOD_RESULT}, please checkout")
        endif()
    endif()
endif()

# CHECK ALL THE SUBMODULES
if(NOT EXISTS "${PROJECT_SOURCE_DIR}/libs/SDL2/CMakeLists.txt")
    message(FATAL_ERROR "The SDL2 submodule was not downloaded! GIT_SUBMODULE was turned off or failed. Please fix this issue before continuing")
endif()

add_subdirectory(libs/SDL2)
target_include_directories(${PROJECT_NAME} PUBLIC libs/SDL2/include)
target_link_directories(${PROJECT_NAME} PRIVATE libs/SDL2)
target_link_libraries(${PROJECT_NAME} SDL2)