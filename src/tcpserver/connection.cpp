#include "connection.hpp"
#include <netinet/ip.h>

#include <thread>
#include <unistd.h>
#include <iostream>
#include <string>

struct Sock_Port
{
    int sock;
    int port;
};


Connection::Connection(int conn_fd, sockaddr_in peer_addr):conn_fd_{conn_fd},peer_addr_{peer_addr}{
}

Connection::~Connection(){
    
    if(connection_thread_.joinable())
        connection_thread_.join();
}

void Connection::start(){

    
    connection_thread_ = std::thread(&Connection::ReadAsync,this);
    
    return;
}


int Connection::ReadAsync(){
    std::string buffer(1024,' ');
    while( read(conn_fd_,buffer.data(),1024) > 0 ){
        std::cout << peer_addr_.sin_port <<">>"<<buffer << std::endl;
        buffer.clear();
    }
    return 0;    
}
