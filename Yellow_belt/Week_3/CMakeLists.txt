project(Week_3)

set(CMAKE_CXX_STANDARD 17)
set(GCC_COVERAGE_COMPILE_FLAGS "-Wall -Werror --std=c++1z")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}" )

add_executable(Sandbox_3 Sandbox.cpp)
add_executable(SynonymsUT_3 SynonymsMain.cpp ../TestRunner/TestRunner.cpp
        synonyms/Synonyms.cpp synonyms/SynonymsUT.cpp)
add_executable(PhoneNumberMain_3 PhoneNumberMain.cpp ../TestRunner/TestRunner.cpp
        phone_number/PhoneNumber.cpp phone_number/PhoneNumberUT.cpp)

add_executable(Rectangle_3 Rectangle.cpp)
add_executable(SumReverseSort_3 SumReverseSort.cpp)

add_executable(BusDecomp_3 program_decomp/main.cpp
        program_decomp/query.cpp program_decomp/responses.cpp
        program_decomp/bus_manager.cpp)