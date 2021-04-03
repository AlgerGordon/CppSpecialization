
add_executable(w1-1_class_templates lectures/0_class_templates.cpp)
add_executable(w1-2_generating_functions lectures/1_generating_functions.cpp)
add_executable(w1-3_cpp17_features lectures/2_cpp17_features.cpp)
add_executable(w1-4_auto_gener_returned_type lectures/3_auto_gener_returned_type.cpp)

add_executable(w1-table table.cpp)
target_link_libraries(w1-table test_runner)

add_executable(w1-my_deque my_deque.cpp)

add_executable(w1-paginator paginator.cpp)
target_link_libraries(w1-paginator test_runner)
