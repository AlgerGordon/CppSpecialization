project(Week_6_FinalProject)

set(CMAKE_CXX_STANDARD 17)
set(GCC_COVERAGE_COMPILE_FLAGS "-Wall -Werror --std=c++1z")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}" )

add_executable(FinalProject main.cpp token.cpp token.h condition_parser_test.cpp
        condition_parser.cpp condition_parser.h
        test_runner.cpp test_runner.h
        date.cpp date.h database.cpp database.h
        node.cpp node.h)