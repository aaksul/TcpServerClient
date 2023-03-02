#pragma once
#include"tcpclient.hpp"
#include<gtest/gtest.h>
#include<gmock/gmock.h>
#include"faketcpsocketclient.hpp"
#include<memory>

using namespace testing;


auto nulldeleter=[](TcpSocketI*){};

class TcpClientTest : public Test{

    public:
    TcpClient tcp_client{};
    FakeTcpSocket fake_tcp_socket{};
    std::shared_ptr<TcpSocketClientI> ptr{&fake_tcp_socket,nulldeleter};
};

TEST_F(TcpClientTest,InitializaSocketTest){
    EXPECT_CALL(fake_tcp_socket,SocketInit()).WillOnce(Return(1));
    tcp_client.InitializeSocket(ptr);
}

TEST_F(TcpClientTest,ConnectWithoutInitializeTest)
{
    tcp_client.ip(0x0100007F);//network order
    tcp_client.port(8007);
    tcp_client.InitializeSocket(ptr);
    EXPECT_CALL(fake_tcp_socket,Connect(Le(0),_,_)).WillOnce(Return(20));
    tcp_client.Connect(ptr);
}




