#pragma once
#include<unistd.h>
#include<sys/socket.h>

class TcpSocketI  
{
    protected:
    public:
        virtual int SocketInit()=0;
        virtual int Close(int sockfd)=0;
        virtual ~TcpSocketI(){}
    
};


class TcpSocket : public TcpSocketI
{
    protected:
    public:
        int SocketInit() override {return socket(AF_INET,SOCK_STREAM,0);}
        int Close(int sockfd) override {return close(sockfd);}
    
};