project(Week_1)

set(CMAKE_CXX_STANDARD 17)
set(GCC_COVERAGE_COMPILE_FLAGS "-Wall -Werror --std=c++1z")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}" )

add_executable(Sandbox_1 Sandbox.cpp)
add_executable(AverageTemp_1 AverageTemp.cpp TaskTracker.cpp)
add_executable(ElementRef_1 ElementRef.cpp)
add_executable(SqrForContainers_1 SqrForContainers.cpp)
add_executable(TemplateOutput_1 TemplateOutput.cpp)
add_executable(TaskTrackerAuthors TaskTrackerAuthors.cpp)
add_executable(RegionBase_1 RegionBase.cpp)
add_executable(BlocksWeight_1 BlocksWeight.cpp)
add_executable(White_belt_check_1 White_belt_check.cpp)
add_executable(TaskTracker TaskTracker.cpp)
