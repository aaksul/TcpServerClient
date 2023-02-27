#pragma once
#include<sys/socket.h>
#include<netinet/ip.h>

class Connection;

class TcpServer
{

private:
    int listenfd;
    Connection* conn_arr;
    u_int32_t ip;
    u_int16_t port;

public:
    TcpServer(){};
    ~TcpServer();
    void Listen(uint16_t);
    void Accept();
    void initializeCon(int,sockaddr_in);
    friend TcpServer& setTcpServer(TcpServer& tcpServer,u_int32_t ip, u_int16_t port);
};
