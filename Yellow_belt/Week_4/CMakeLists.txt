project(Week_4)

set(CMAKE_CXX_STANDARD 17)
set(GCC_COVERAGE_COMPILE_FLAGS "-Wall --std=c++1z")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}" )

add_executable(IteratorsIntro lectures/IteratorsIntro.cpp)
add_executable(IteratorsInAlgs lectures/IteratorsInAlgs.cpp)
add_executable(IteratorInsert lectures/IteratorInsert.cpp)
add_executable(PrintVectorPart PrintVectorPart.cpp)
add_executable(FindGreaterElements FindGreaterElements.cpp)
add_executable(SplitIntoWords SplitIntoWords.cpp)