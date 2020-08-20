
add_executable(macros_intro lectures/macros_intro.cpp)

add_executable(LOG_MACRO LOG_MACRO.cpp)
target_link_libraries(LOG_MACRO test_runner)

add_executable(SORT_BY avia_scanner/SORT_BY.cpp)
target_link_libraries(SORT_BY test_runner)

add_executable(UPDATE_FIELD avia_scanner/UPDATE_FIELD.cpp)
target_link_libraries(UPDATE_FIELD test_runner)

add_executable(BAD_MACRO BAD_MACRO.cpp)
target_link_libraries(BAD_MACRO test_runner)

add_executable(UNIQ_ID UNIQ_ID.cpp)