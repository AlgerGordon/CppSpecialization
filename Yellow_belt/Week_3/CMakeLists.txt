project(Week_3)

add_executable(Sandbox Sandbox.cpp )
add_executable(SynonymsUT SynonymsMain.cpp TestRunner.cpp Synonyms.cpp SynonymsUT.cpp)
add_executable(MainTest MainTest.cpp TestRunner.cpp Rectangle.cpp PhoneNumber.cpp SumReverseSort.cpp )