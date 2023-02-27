

add_subdirectory(CommandParserTest)

add_executable(testMain testMain.cpp)

target_link_libraries(testMain CommandParserTest)
target_link_libraries(testMain :libgmock.a :libgtest.a)