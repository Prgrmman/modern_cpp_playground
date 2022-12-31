# Always set the minimum version
cmake_minimum_required(VERSION 3.24.0)

# Project name
project(listLib VERSION 1.0.0 DESCRIPTION "messing around with linked lists")

add_definitions("-std=c++14")

# Conan stuff
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()


# Testing definitions
include_directories(include)
enable_testing()
add_executable(persistent_list_test
    test/persistent_list_test.cpp
    src/persistent_list.cpp
)
target_link_libraries(
  persistent_list_test
  ${CONAN_LIBS}
)
#set_target_properties(persistent_list_test PROPERTIES PUBLIC_HEADER include/persistent_list.hpp)
