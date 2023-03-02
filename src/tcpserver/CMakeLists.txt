

add_library(tcpserver tcpserver.cpp)


target_include_directories(tcpserver PUBLIC ${CMAKE_SOURCE_DIR}/include/tcpserver)


add_library(connection connection.cpp)

target_link_libraries(tcpserver PRIVATE tcpsocketserver PRIVATE connection)
