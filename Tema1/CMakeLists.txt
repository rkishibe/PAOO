cmake_minimum_required(VERSION 3.10)
project(Tema1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(include)

add_executable(Tema1 src/main.cpp src/Cinema.cpp src/Movie.cpp)