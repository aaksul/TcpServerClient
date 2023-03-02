


add_library(commandparsertest INTERFACE)


target_include_directories(commandparsertest INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(commandparsertest INTERFACE commandparserserver tcpserver commandparserclient tcpclient)