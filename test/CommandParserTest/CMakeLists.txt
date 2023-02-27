


add_library(CommandParserTest INTERFACE)


target_include_directories(CommandParserTest INTERFACE ${CMAKE_SOURCE_DIR}/test/CommandParserTest)

target_link_libraries(CommandParserTest INTERFACE CommandParserServer TcpServer)