#include"tcpsocketclient.hpp"
#include"tcpclient.hpp"
#include<iostream>
#include<arpa/inet.h>
#include<string>
#include<memory>




void TcpClient::InitializeSocket(std::shared_ptr<TcpSocketI> tcp_socket_i){
    sock_fd_=tcp_socket_i->SocketInit();
    if( sock_fd_ < 0 )
        std::cout << "Error in TcpClient socket";
}

void TcpClient::Connect(std::shared_ptr<TcpSocketClientI> tcp_socket_client_i){

    sockaddr_in addr{};
    addr.sin_family=AF_INET;
    addr.sin_port=htons(port_);
    addr.sin_addr.s_addr=ip_;

    int status=tcp_socket_client_i->Connect(sock_fd_,(sockaddr*)&addr,sizeof(addr));
    std::string ip_str(18,'\0');
    inet_ntop(addr.sin_family,&(addr.sin_addr),&(*ip_str.begin()),sizeof(ip_str));
    if(status!=0)
        std::cout << "Error while connect to:" << ip_str;
}

void TcpClient::Close(std::shared_ptr<TcpSocketI> tcp_socket_i){

    int status = tcp_socket_i->Close(sock_fd_);

    if(status!=0)
        std::cout << "Error in while close\n";
}



