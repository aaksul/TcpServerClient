#pragma once

#include <sys/socket.h>
#include <netinet/ip.h>
class Connection
{
private:
    int conn_fd_;
    sockaddr_in peer_adr_;//address of peer socket

public:
    Connection(int,struct sockaddr_in);
    ~Connection();
    void start();
};

namespace thread_safe{

    void* Read(void*);
}
