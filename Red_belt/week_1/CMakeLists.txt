project(Week_1)

add_subdirectory(class_templates)
add_subdirectory(MACROs)

add_executable(w1-yellow_belt_check yellow_belt_check.cpp)

add_executable(w1-rational rational/rational.cpp rational/rational_UT.cpp
        rational/rational_main.cpp)
target_link_libraries(w1-rational test_runner)

