
add_executable(w1-macros_intro lectures/macros_intro.cpp)

add_executable(w1-LOG_MACRO LOG_MACRO.cpp)
target_link_libraries(w1-LOG_MACRO test_runner)

add_executable(w1-SORT_BY avia_scanner/SORT_BY.cpp)
target_link_libraries(w1-SORT_BY test_runner)

add_executable(w1-UPDATE_FIELD avia_scanner/UPDATE_FIELD.cpp)
target_link_libraries(w1-UPDATE_FIELD test_runner)

add_executable(w1-BAD_MACRO BAD_MACRO.cpp)
target_link_libraries(w1-BAD_MACRO test_runner)

add_executable(w1-UNIQ_ID UNIQ_ID.cpp)