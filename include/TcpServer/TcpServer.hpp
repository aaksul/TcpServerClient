#pragma once
#include<sys/socket.h>
#include<netinet/ip.h>

class Connection;

class TcpServer
{

private:
    int listenfd;
    Connection* conn_arr;

public:
    TcpServer();
    ~TcpServer();
    void Listen(uint16_t);
    void Accept();
    void initializeCon(int,sockaddr_in);
};
