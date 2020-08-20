project(Week_1)

add_subdirectory(class_templates)
add_subdirectory(MACROs)

add_executable(Yellow_belt_check Yellow_belt_check.cpp)

add_executable(Rational rational/Rational.cpp rational/RationalUT.cpp
        rational/RationalTestMain.cpp)
target_link_libraries(Rational test_runner)

