

add_library(tcpclient tcpclient.cpp)

target_include_directories(tcpclient PUBLIC ${CMAKE_SOURCE_DIR}/include/tcpclient)

target_link_libraries(tcpclient tcpsocketclient)


