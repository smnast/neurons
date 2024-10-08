cmake_minimum_required(VERSION 3.10)

project(neurons)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(SDL2 REQUIRED)

add_subdirectory(src)
