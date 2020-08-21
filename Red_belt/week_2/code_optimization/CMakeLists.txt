
# set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/IO_bin")

add_executable(measure lectures/1_measure.cpp)
target_link_libraries(measure profile)
add_executable(create_input lectures/create_input.cpp)

# set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})
add_executable(optimization_intro lectures/0_optimization_intro.cpp)

add_executable(sort_students sort_students.cpp)
target_link_libraries(sort_students test_runner)
target_link_libraries(sort_students profile)

add_executable(learner learner.cpp)
target_link_libraries(learner profile)