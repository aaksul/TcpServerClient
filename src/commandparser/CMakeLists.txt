
add_library(commandparserserver commandparserserver.cpp)
target_include_directories(commandparserserver PUBLIC ${CMAKE_SOURCE_DIR}/include/commandparser)
target_include_directories(commandparserserver PRIVATE ${CMAKE_SOURCE_DIR}/include/tcpserver)
add_library(commandparserclient commandparserclient.cpp)
target_include_directories(commandparserclient PUBLIC ${CMAKE_SOURCE_DIR}/include/commandparser)
target_include_directories(commandparserclient PRIVATE ${CMAKE_SOURCE_DIR}/include/tcpclient)
