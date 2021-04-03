cmake_minimum_required(VERSION 3.16)

project(Red_belt)

set(CMAKE_CXX_STANDARD 17)
set(GCC_COVERAGE_COMPILE_FLAGS "-Wall -Werror --std=c++1z")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}" )

add_subdirectory(week_1)
add_subdirectory(week_2)
add_subdirectory(week_3)
add_subdirectory(week_4)
add_subdirectory(week_5)
add_subdirectory(week_6_FinalProject)

add_subdirectory(test_runner)
add_subdirectory(profile)
add_subdirectory(my_print)