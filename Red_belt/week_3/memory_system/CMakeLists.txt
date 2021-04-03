add_executable(w3-0_new_operator lectures/0_new_operator.cpp)
add_executable(w3-1_delete_operator lectures/1_delete_operator.cpp)
add_executable(w3-2_NewDelete_for_arrays lectures/2_NewDelete_for_arrays.cpp)
add_executable(w3-3_ptrs_arithmetics lectures/3_ptrs_arithmetics.cpp)
add_executable(w3-4_begin_end_in_vector lectures/4_begin_end_in_vector.cpp)
add_executable(w3-5_const_const_ptr lectures/5_const_const_ptr.cpp)


add_executable(w3-object_pool object_pool.cpp)
target_link_libraries(w3-object_pool test_runner)

add_executable(w3-swap_sort_copy swap_sort_copy.cpp)
target_link_libraries(w3-swap_sort_copy test_runner)

add_executable(w3-simple_vector simple_vector/simple_vector_test.cpp)
target_link_libraries(w3-simple_vector test_runner)

add_executable(w3-linked_list linked_list.cpp)
target_link_libraries(w3-linked_list test_runner)