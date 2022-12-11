
project(TcpServerClient)

cmake_minimum_required(VERSION 3.21)

set(CMAKE_CXX_FLAGS "-std=c++03")

set(CMAKE_CXX_STANDARD_REQUIRED True)


add_compile_options(-Wall -Wextra -Wpedantic)


add_subdirectory(src)

add_executable(TcpServerMain TcpServerMain.cpp)

target_link_libraries(TcpServerMain TcpServer)


add_executable(TcpClientMain TcpClientMain.cpp)

target_link_libraries(TcpClientMain TcpClient)
