#pragma once
#include"tcpsocketI.hpp"
#include<sys/socket.h>

struct sockaddr;

class TcpSocketServerI : public TcpSocket  
{
    public:
        virtual int Listen(int)=0;
        virtual int Bind(int sockfd,const struct sockaddr* addr,unsigned int addrlen)=0;
        virtual int Accept(int,sockaddr*,unsigned int*)=0;
};


class TcpSocketServer : public TcpSocketServerI
{
    public:
        int Listen(int sockfd) override;
        int Bind(int sockfd,const struct sockaddr* addr,unsigned int addrlen) override {return bind(sockfd,addr,addrlen);}
        int Accept(int,sockaddr*,unsigned int*) override;
        //int Read(int,void*,size_t) override;

};

