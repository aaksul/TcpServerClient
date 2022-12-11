

add_library(TcpServer TcpServer.cpp)

target_include_directories(TcpServer PUBLIC ${CMAKE_SOURCE_DIR}/include/TcpServer)


add_library(Connection Connection.cpp)

target_link_libraries(TcpServer PRIVATE Connection)
