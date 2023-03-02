
project(tcpserverclient)

cmake_minimum_required(VERSION 3.21)

set(CMAKE_CXX_FLAGS "-std=c++17")

set(CMAKE_CXX_STANDARD_REQUIRED True)


add_compile_options(-Wall -Wextra -Wpedantic)


add_subdirectory(src)
add_subdirectory(test)

add_executable(tcpservermain tcpservermain.cpp)

target_link_libraries(tcpservermain tcpserver commandparserserver tcpsocketserver)


add_executable(tcpclientmain tcpclientmain.cpp)

target_link_libraries(tcpclientmain tcpclient commandparserclient tcpsocketclient)
