#pragma once
#include<string>
#include<memory>


class TcpSocketI;
class TcpSocketClientI;

class TcpClient
{
private:
    int sock_fd_;
    u_int32_t ip_;//must be set as network byte order
    u_int16_t port_;//must be set as host-order
public:
    void InitializeSocket(std::shared_ptr<TcpSocketI>);
    void Connect(std::shared_ptr<TcpSocketClientI>);
    void Close(std::shared_ptr<TcpSocketI>);
    const u_int32_t& ip() const{return ip_;}
    u_int32_t& ip(u_int32_t ip) {return (ip_=ip);}
    const u_int16_t& port() const{return port_;}
    u_int16_t& port(u_int16_t port){return (port_=port);}
};