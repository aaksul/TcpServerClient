#include"tcpsocketclient.hpp"
#include"sys/socket.h"

int TcpSocketClient::Connect(int sockfd,sockaddr* addr,unsigned int addrlen){
    return connect(sockfd,addr,addrlen);
}