
add_library(tcpclienttest INTERFACE)

target_include_directories(tcpclienttest INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(tcpclienttest INTERFACE tcpclient)
