cmake_minimum_required(VERSION 3.16)

project(White_belt)

set(GCC_COVERAGE_COMPILE_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}" )
set(CMAKE_CXX_STANDARD 17)

add_subdirectory(Week_1)
add_subdirectory(Week_2)
add_subdirectory(Week_3)
add_subdirectory(Week_4)
add_subdirectory(Week_5)