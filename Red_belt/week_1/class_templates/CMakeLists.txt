
add_executable(1_class_templates lectures/1_class_templates.cpp)
add_executable(2_generating_functions lectures/2_generating_functions.cpp)
add_executable(3_cpp17_features lectures/3_cpp17_features.cpp)
add_executable(4_auto_gener_returned_type lectures/4_auto_gener_returned_type.cpp)

add_executable(table table.cpp)
target_link_libraries(table test_runner)

add_executable(my_deque my_deque.cpp)

add_executable(paginator paginator.cpp)
target_link_libraries(paginator test_runner)
