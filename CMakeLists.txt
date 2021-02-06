cmake_minimum_required(VERSION 3.17)
project(homework1)

set(CMAKE_CXX_STANDARD 17)
# If wanting to run another main program, must replace the current main program with the one you want to run.
# Main programs are: timeIt.cpp timeIt2.cpp cStyleStrings.cpp
add_executable(homework1 timeIt.cpp StopWatch.cpp StopWatch.hpp)
