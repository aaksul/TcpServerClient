#include "Connection.hpp"
#include <sys/socket.h>
#include <netinet/ip.h>
#include <pthread.h>
#include <unistd.h>
#include <iostream>
#include <cstring>

struct sock_port
{
    int sock;
    int port;
};


Connection::Connection(int connfd,struct sockaddr_in peer_socket){
    
    Connection::connfd=connfd;
    Connection::peerAdr=peer_socket;

}
Connection::~Connection(){
    
}

void Connection::start(){
    //thread create give argument connfd
    pthread_t t;

    
    sock_port* sockport=new sock_port();
    sockport->port=ntohs(peerAdr.sin_port);
    sockport->sock=connfd;

    pthread_create(&t,NULL,threadSafe::Read,sockport);

}



void* threadSafe::Read(void* arg){
    pthread_detach(pthread_self());
    sock_port* sockport = static_cast<sock_port*>(arg);
    int readfd = sockport->sock;
    int port = sockport->port; 
    char buffer[1024];
    while( read(readfd,buffer,1024) > 0 ){
        std::cout << port <<">>"<<buffer << std::endl;
        std::memset(buffer,'\0',1024);
    }
    close(readfd);    
    delete sockport;
    return NULL;    
}