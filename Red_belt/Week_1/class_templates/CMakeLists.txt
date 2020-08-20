
add_executable(ClassTemplatesIntro lectures/1_ClassTemplates.cpp)
add_executable(GeneratingFunctionsIntro lectures/2_GeneratingFunctions.cpp)
add_executable(Cpp17Features lectures/3_Cpp17Features.cpp)
add_executable(AutoGenerReturnedVal lectures/4_AutoGenerReturnedVal.cpp)

add_executable(Table Table.cpp)
target_link_libraries(Table test_runner)

add_executable(MyDeque MyDeque.cpp)

add_executable(Paginator Paginator.cpp)
target_link_libraries(Paginator test_runner)
