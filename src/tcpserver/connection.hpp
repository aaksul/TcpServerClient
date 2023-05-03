#pragma once
#include <thread>
#include <netinet/ip.h>
class Connection
{
private:
    int conn_fd_;
    sockaddr_in peer_addr_;//address of peer socket
    std::thread connection_thread_;
    int ReadAsync();
public:
    Connection(int con_fd,struct sockaddr_in peer_addr);
    ~Connection();
    void start();
};

