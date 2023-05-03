#pragma once
#include<sys/socket.h>
#include<netinet/ip.h>
#include<memory>
#include<vector>
class Connection;

class TcpSocketI;
class TcpSocketServerI;

class TcpServer
{

private:
    int listen_fd_;
    u_int32_t ip_;//must be set as network order
    u_int16_t port_;//must be set as host order
    std::vector<Connection*> connections_;
    Connection* InitializeConnection(int connection_sock_fd,sockaddr_in peer_socket);
public:
    TcpServer(): ip_{},port_{}{};
    TcpServer(uint32_t ip ,uint16_t port) : ip_(ip), port_(port) {}
    ~TcpServer();
    void InitializeSocket(std::shared_ptr<TcpSocketI>);
    void Listen(std::shared_ptr<TcpSocketServerI>);
    void Accept(std::shared_ptr<TcpSocketServerI>);
    void Close(std::shared_ptr<TcpSocketI>);
    const u_int32_t& ip() const{return ip_;}
    u_int32_t& ip(u_int32_t ip) {return (ip_=ip);}
    const u_int16_t& port() const{return port_;}
    u_int16_t& port(u_int16_t port){return (port_=port);}

};
