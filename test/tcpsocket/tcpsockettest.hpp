#pragma once

#include<gtest/gtest.h>
#include<gmock/gmock.h>
#include<tcpsocketclient.hpp>
#include<netinet/in.h>
#include<iostream>
#include<stdio.h>
using namespace testing;



class TcpSocketClientTest : public ::Test{
    protected:
        TcpSocketClient tcp_socket_client_t_;
};


TEST_F(TcpSocketClientTest,SocketInitializationTest)
{
    EXPECT_THAT(tcp_socket_client_t_.SocketInit(),Ne(-1));
}


TEST_F(TcpSocketClientTest,SocketConnectFailTest){
    int sock_fd=tcp_socket_client_t_.SocketInit();
    sockaddr_in s_addr_in{};

    unsigned char ip[4] = {127u,0u,0u,1u};//not valid ip adress
    u_int32_t* ip_32 = reinterpret_cast<u_int32_t*>(ip);
    s_addr_in.sin_family=AF_INET;
    s_addr_in.sin_addr.s_addr=*ip_32;
    s_addr_in.sin_port=5000;
    EXPECT_THAT(tcp_socket_client_t_.Connect( sock_fd,(sockaddr*)(&s_addr_in),sizeof(sockaddr) ) ,Eq(-1));
}

TEST_F(TcpSocketClientTest,SocketConnectSuccessedTest){
    int sock_fd=tcp_socket_client_t_.SocketInit();
    

    unsigned char ip[4] = {127u,0u,0u,1u};//not valid ip adress
    u_int32_t* ip_32 = reinterpret_cast<u_int32_t*>(ip);
    popen("nc -l 8083","r");//open fully 
    sockaddr_in s_addr_in{};
    s_addr_in.sin_family=AF_INET;
    s_addr_in.sin_addr.s_addr=*ip_32;
    s_addr_in.sin_port=htons(8083);
    
    EXPECT_THAT(tcp_socket_client_t_.Connect( sock_fd,(sockaddr*)(&s_addr_in),sizeof(sockaddr) ) ,Eq(0));

}

TEST_F(TcpSocketClientTest,SocketCloseSuccessedTest){
    int sock_fd=tcp_socket_client_t_.SocketInit();
    EXPECT_THAT(tcp_socket_client_t_.Close(sock_fd),Eq(0));
}