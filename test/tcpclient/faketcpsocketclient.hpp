#pragma once
#include<gmock/gmock.h>
#include"tcpsocketclient.hpp"


class FakeTcpSocket : public TcpSocketClientI
{
    public:

        MOCK_METHOD(int,SocketInit,(),(override));
        MOCK_METHOD(int,Close,(int sockfd),(override));
        MOCK_METHOD(int,Connect,(int sockfd,sockaddr* addr,unsigned int addrlen),(override));
        //MOCK_METHOD(int,Read,(int,void*,size_t),(override));
        //MOCK_METHOD(int,Write,(),(override));
        ~FakeTcpSocket(){}
};
