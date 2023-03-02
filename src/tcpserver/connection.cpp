#include "connection.hpp"
#include <sys/socket.h>
#include <netinet/ip.h>
#include <pthread.h>
#include <unistd.h>
#include <iostream>
#include <cstring>

struct Sock_Port
{
    int sock;
    int port;
};


Connection::Connection(int conn_fd_,struct sockaddr_in peer_socket){
    
    Connection::conn_fd_=conn_fd_;
    Connection::peer_adr_=peer_socket;

}
Connection::~Connection(){
    
}

void Connection::start(){
    //thread create give argument conn_fd_
    pthread_t t;

    
    Sock_Port* sock_port=new Sock_Port();
    sock_port->port=ntohs(peer_adr_.sin_port);
    sock_port->sock=conn_fd_;

    pthread_create(&t,NULL,thread_safe::Read,sock_port);

}



void* thread_safe::Read(void* arg){
    pthread_detach(pthread_self());
    Sock_Port* sock_port = static_cast<Sock_Port*>(arg);
    int readfd = sock_port->sock;
    int port = sock_port->port; 
    char buffer[1024];
    while( read(readfd,buffer,1024) > 0 ){
        std::cout << port <<">>"<<buffer << std::endl;
        std::memset(buffer,'\0',1024);
    }
    close(readfd);    
    delete sock_port;
    return NULL;    
}