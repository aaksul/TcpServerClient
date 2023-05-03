#pragma once
#include"tcpclient.hpp"
#include<gtest/gtest.h>
#include<gmock/gmock.h>
#include"faketcpsocketclient.hpp"
#include<memory>
#include<errno.h>

using namespace testing;


auto nulldeleter=[](TcpSocketI*){};

class TcpClientTest : public Test{

    public:
    TcpClient tcp_client{};
    FakeTcpSocket fake_tcp_socket{};
    std::shared_ptr<TcpSocketClientI> tcp_socket_ptr{&fake_tcp_socket,nulldeleter};
};

TEST_F(TcpClientTest,InitializaSocketTest){
    EXPECT_CALL(fake_tcp_socket,SocketInit()).WillOnce(Return(1));
    EXPECT_THAT(tcp_client.InitializeSocket(tcp_socket_ptr),Eq(1));
}

TEST_F(TcpClientTest,ConnectWithoutInitializeTest)
{
    tcp_client.ip(0x0100007F);//network order
    tcp_client.port(8007);
    ON_CALL(fake_tcp_socket,SocketInit).WillByDefault(Return(5));//Socket creation is being mocked. 5 is a new file descriptor
    tcp_client.InitializeSocket(tcp_socket_ptr);
    EXPECT_CALL(fake_tcp_socket,Connect(5,_,_)).WillOnce(Return(0));
    EXPECT_THAT(tcp_client.Connect(tcp_socket_ptr),Eq(0));
}


TEST_F(TcpClientTest,ConnectWithoutInitializeTest2)
{
    tcp_client.ip(0x0100007F);//network order
    tcp_client.port(8007);
    ON_CALL(fake_tcp_socket,SocketInit).WillByDefault(Return(-1));
    tcp_client.InitializeSocket(tcp_socket_ptr);
    std::shared_ptr<TcpSocketClientI>tcp_new_socket_ptr(new TcpSocketClient());
    EXPECT_THAT(tcp_client.Connect(tcp_new_socket_ptr),Eq(-1));
}


TEST_F(TcpClientTest,DISABLED_CloseSocketTest)
{
    tcp_client.ip(0x0100007F);//network order
    tcp_client.port(8007);
    ON_CALL(fake_tcp_socket,SocketInit).WillByDefault(Return(10));
    tcp_client.InitializeSocket(tcp_socket_ptr);
    std::shared_ptr<TcpSocketI>tcp_new_socket_ptr(new TcpSocket());
    EXPECT_THAT(tcp_client.Close(tcp_new_socket_ptr),Eq(0));
}

