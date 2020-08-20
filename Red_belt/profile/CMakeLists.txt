

add_library(profile INTERFACE)
target_sources(profile INTERFACE profile.h)
target_include_directories(profile INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})