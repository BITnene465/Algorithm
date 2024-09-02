cmake_minimum_required(VERSION 3.26)
project(DS_ALimplement)

set(CMAKE_CXX_STANDARD 17)

include_directories(.)

add_executable(DS_ALimplement
        MyTrees_imp.h
        MyTrees.h
        main.cpp)
