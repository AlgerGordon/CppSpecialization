add_executable(optimization_intro lectures/1_optimization_intro.cpp)
add_executable(measure lectures/2_measure.cpp)
# add_executable(create_input lectures/create_input.cpp)

add_executable(sort_students sort_students.cpp)
target_link_libraries(sort_students test_runner)
target_link_libraries(sort_students profile)