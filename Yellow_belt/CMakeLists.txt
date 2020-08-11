cmake_minimum_required(VERSION 3.16)

project(Yellow_belt)

set(CMAKE_CXX_STANDARD 17)
set(GCC_COVERAGE_COMPILE_FLAGS "-Wall -Werror --std=c++1z")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}" )

add_subdirectory(Week_1)
add_subdirectory(Week_2)
add_subdirectory(Week_3)
add_subdirectory(Week_4)
add_subdirectory(Week_5)
add_subdirectory(Week_6_FinalProject)
add_subdirectory(TestRunner)