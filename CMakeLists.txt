cmake_minimum_required(VERSION 3.10)
project(PAOO)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(include)

add_executable(PAOO src/main.cpp src/Cinema.cpp src/Movie.cpp src/IMAXCinema.cpp)
