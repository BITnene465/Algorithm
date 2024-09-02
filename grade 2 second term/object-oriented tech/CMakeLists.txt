cmake_minimum_required(VERSION 3.26)
project(object_oriented_tech)

set(CMAKE_CXX_STANDARD 14)

include_directories(./src/inc)

aux_source_directory(./src/src SRC1)

add_executable(object_oriented_tech main.cpp ${SRC1})



