project(Week_1)

add_executable(Yellow_belt_check Yellow_belt_check.cpp)

add_executable(Rational rational/Rational.cpp rational/RationalUT.cpp
        rational/RationalTestMain.cpp)
target_link_libraries(Rational test_runner)

add_executable(MacrosIntro lectures/MacrosIntro.cpp)
add_executable(ClassTemplatesIntro lectures/1_ClassTemplates.cpp)
add_executable(GeneratingFunctionsIntro lectures/2_GeneratingFunctions.cpp)
add_executable(Cpp17Features lectures/3_Cpp17Features.cpp)
add_executable(AutoGenerReturnedVal lectures/4_AutoGenerReturnedVal.cpp)

add_executable(LOG_MACRO LOG_MACRO.cpp)
target_link_libraries(LOG_MACRO test_runner)

add_executable(SORT_BY AviaScanner/SORT_BY.cpp)
target_link_libraries(SORT_BY test_runner)


add_executable(UPDATE_FIELD AviaScanner/UPDATE_FIELD.cpp)
target_link_libraries(UPDATE_FIELD test_runner)

add_executable(BAD_MACRO BAD_MACRO.cpp)
target_link_libraries(BAD_MACRO test_runner)

add_executable(UNIQ_ID UNIQ_ID.cpp)

add_executable(Table Table.cpp)
target_link_libraries(Table test_runner)

add_executable(MyDeque MyDeque.cpp)

add_executable(Paginator Paginator.cpp)
target_link_libraries(Paginator test_runner)

