#include"tcpsocketserver.hpp"
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<string>
#include<iostream>
int TcpSocketServer::Accept(int sockfd,sockaddr* addr,unsigned int* addrlen){
    
    int accepted_fd=accept4(sockfd,addr,addrlen,0);
    if(accepted_fd==-1)
    {
        std::cout << "error while accepting connection. error code is="<< errno <<"\n";
        return -1;
    }
    sockaddr_in* accepted_peer = reinterpret_cast<sockaddr_in*>(addr);
    std::string peer_ip_str(18,' ');
    inet_ntop(accepted_peer->sin_family,&(accepted_peer->sin_addr),&(*peer_ip_str.begin()),sizeof(peer_ip_str));
    std::cout << "Accepted connection from:" << peer_ip_str << "port:" << ntohs(accepted_peer->sin_port) << "\n";
    return accepted_fd;
}

int TcpSocketServer::Listen(int sockfd){
    int status=listen(sockfd,10);
    return status;
}