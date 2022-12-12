#pragma once

#include <sys/socket.h>
#include <netinet/ip.h>
class Connection
{
private:
    int connfd;
    sockaddr_in peerAdr;//address of peer socket

public:
    Connection(int,struct sockaddr_in);
    ~Connection();
    void start();
};

namespace threadSafe{

    void* Read(void*);
}
