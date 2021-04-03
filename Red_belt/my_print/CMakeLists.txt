add_library(my_print INTERFACE)
target_sources(my_print INTERFACE my_print.h)
target_include_directories(my_print INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})