#include<iostream>
#include"tcpserver.hpp"
#include"connection.hpp"
#include<sys/socket.h>
#include<unistd.h>
#include<arpa/inet.h>
#include"tcpsocketserver.hpp"

void TcpServer::InitializeSocket(std::shared_ptr<TcpSocketI> tcp_socket){
    listen_fd_=tcp_socket->SocketInit();
}

void TcpServer::Listen(std::shared_ptr<TcpSocketServerI> tcp_socket_server){

    sockaddr_in addr{};
    
    addr.sin_addr.s_addr=ip_;
    addr.sin_port=htons(port_);
    addr.sin_family=AF_INET;

    int status=tcp_socket_server->Bind(listen_fd_,(sockaddr*)(&addr),sizeof(sockaddr));
    
    if(status!=0)
    {
        std::cout << "error occured in binding\n";
        return;
    }        
    
    status=tcp_socket_server->Listen(listen_fd_);
    
    if(status!=0){
        std::cout<<"error occured in listening\n";
        return;
    }

}


void TcpServer::Accept(std::shared_ptr<TcpSocketServerI> tcp_socket_server){
    
    sockaddr_in peer_socket{};
    socklen_t sizeaddr=sizeof(sockaddr_in);
    int connection_fd=tcp_socket_server->Accept(listen_fd_,(sockaddr*)(&peer_socket),&sizeaddr);
    if(connection_fd==-1)
        return;

    Connection* connection=InitializeConnection(connection_fd,peer_socket);
    connections_.push_back(connection);
    //connection->start();
}

Connection* TcpServer::InitializeConnection(int connection_sock_fd,sockaddr_in peer_socket){
    //Create a connection
    return new Connection(connection_sock_fd,peer_socket);    
}

TcpServer::~TcpServer(){
    TcpSocket tcpsocket;
    for(auto& connection : connections_){
        connection->~Connection();
    }

}