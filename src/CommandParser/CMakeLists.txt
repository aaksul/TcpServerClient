
add_library(CommandParserServer CommandParserServer.cpp)

target_include_directories(CommandParserServer PUBLIC ${CMAKE_SOURCE_DIR}/include/CommandParser)
target_include_directories(CommandParserServer PRIVATE ${CMAKE_SOURCE_DIR}/include/TcpServer)
