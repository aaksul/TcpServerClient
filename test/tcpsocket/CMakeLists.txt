
add_library(tcpsockettest INTERFACE)

target_include_directories(tcpsockettest INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(tcpsockettest INTERFACE tcpsocketclient)