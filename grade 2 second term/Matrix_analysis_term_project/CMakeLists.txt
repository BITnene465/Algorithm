cmake_minimum_required(VERSION 3.26)
project(Matrix_analysis_term_project)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Matrix_analysis_term_project
        main.cpp
        Matrix.cpp
        MatrixDecomposer.cpp)
