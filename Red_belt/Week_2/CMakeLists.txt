project(Week_2)

set(CMAKE_CXX_STANDARD 17)
set(GCC_COVERAGE_COMPILE_FLAGS "-Wall --std=c++1z")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")

add_executable(SecondRuleOfOptimization lectures/SecondRuleOfOptimization.cpp)
add_executable(Measure lectures/Measure.cpp)
# add_executable(CreateInput lectures/CreateInput.cpp)