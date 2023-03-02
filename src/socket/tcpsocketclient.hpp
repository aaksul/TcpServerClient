#pragma once
#include"tcpsocketI.hpp"

class TcpSocketClientI : public TcpSocket
{
    public:
        virtual int Connect(int sockfd,sockaddr* addr,unsigned int addrlen)=0;
        virtual ~TcpSocketClientI(){}
};


class TcpSocketClient : public TcpSocketClientI
{
    public:
        TcpSocketClient()=default;
        ~TcpSocketClient()=default;
        int Connect(int sockfd,sockaddr* addr,unsigned int addrlen) override;
};