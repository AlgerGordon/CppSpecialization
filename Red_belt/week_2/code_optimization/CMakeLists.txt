
# set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/IO_bin")

add_executable(w2-measure lectures/1_measure.cpp)
target_link_libraries(w2-measure profile)
add_executable(w2-create_input lectures/create_input.cpp)

# set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})
add_executable(w2-optimization_intro lectures/0_optimization_intro.cpp)

add_executable(w2-sort_students sort_students.cpp)
target_link_libraries(w2-sort_students test_runner)
target_link_libraries(w2-sort_students profile)

add_executable(w2-learner learner.cpp)
target_link_libraries(w2-learner profile)