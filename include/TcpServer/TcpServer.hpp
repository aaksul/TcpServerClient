#pragma once

class Connection;

class TcpServer
{
private:
    Connection* conn_arr;
public:
    TcpServer(/* args */);
    ~TcpServer();
};

TcpServer::TcpServer(/* args */)
{
}

TcpServer::~TcpServer()
{
}
