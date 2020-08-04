cmake_minimum_required(VERSION 3.16)
project(MyPrint)

set(CMAKE_CXX_STANDARD 17)
set(GCC_COVERAGE_COMPILE_FLAGS "-Wall --std=c++1z")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}" )

add_library(TestRunner TestRunner.cpp)
target_include_directories(TestRunner PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})