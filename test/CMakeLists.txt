

add_subdirectory(commandparsertest)
add_subdirectory(tcpsocket)
add_subdirectory(tcpclient)
add_executable(testmain testmain.cpp)

target_link_libraries(testmain commandparsertest tcpsockettest tcpclienttest)
target_link_libraries(testmain :libgmock.a :libgtest.a)