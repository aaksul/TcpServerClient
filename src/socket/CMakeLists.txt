


add_library(tcpsocketclient tcpsocketclient.cpp)
target_include_directories(tcpsocketclient INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})


add_library(tcpsocketserver tcpsocketserver.cpp)
target_include_directories(tcpsocketserver INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
