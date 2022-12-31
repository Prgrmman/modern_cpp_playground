# Always set the minimum version
cmake_minimum_required(VERSION 3.24.0)

# Project name
project(listLib VERSION 1.0.0 DESCRIPTION "messing around with linked lists")

add_definitions("-std=c++14")

# Conan stuff
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()


add_library(listLib SHARED
    src/persistent_list.cpp
)


# Configure the directories to search for header files.
target_include_directories(${PROJECT_NAME} PRIVATE include)
#include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

# Set the shared object version property to the project's major version.
set_target_properties(${PROJECT_NAME} PROPERTIES SOVERSION ${PROJECT_VERSION_MAJOR})

# public headers to install
set_target_properties(listLib PROPERTIES PUBLIC_HEADER include/persistent_list.hpp)

#TODO missing install target