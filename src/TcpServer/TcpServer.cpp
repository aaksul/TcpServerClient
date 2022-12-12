#include<iostream>
#include<TcpServer.hpp>
#include"Connection.hpp"
#include<sys/socket.h>
#include<unistd.h>
#include<arpa/inet.h>

TcpServer::TcpServer(){

    //this->conn_arr = new Connection[30]();
    

}

void TcpServer::Listen(uint16_t port_num){

    sockaddr_in bind_addr;
    bind_addr.sin_family=AF_INET;
    bind_addr.sin_port=htons(port_num);
    bind_addr.sin_addr.s_addr=INADDR_ANY;

    int sockfd = socket(AF_INET,SOCK_STREAM,0);
    
    this->listenfd=sockfd;

    int err=bind(sockfd,(struct sockaddr*)(&bind_addr),sizeof(bind_addr));

    if(err<0){
        std::cout<< "error occured in binding";
    }
    
    err=listen(this->listenfd,10);
    if(err<0){
        std::cout<<"error occured in listening";
    }



}


void TcpServer::Accept(){
    struct sockaddr_in peer_socket;
    
    socklen_t addrlen=sizeof(sockaddr_in);
    
    int consockfd=accept(this->listenfd,(struct sockaddr*)&peer_socket,&addrlen);
    uint16_t port_num=ntohs(peer_socket.sin_port);
    std::cout << "A connection is established, client port is:" << port_num  ;

    char ipstr[INET_ADDRSTRLEN];
    inet_ntop(AF_INET,(struct sockaddr_in*)&peer_socket.sin_addr,ipstr,sizeof(ipstr));
    std::cout << " and address is: " << ipstr<< std::endl;
    initializeCon(consockfd,peer_socket);
    
}

void TcpServer::initializeCon(int consockfd,sockaddr_in peer_socket){
    //Create a connection
    Connection con(consockfd,peer_socket);
    con.start();
}


TcpServer::~TcpServer(){

    close(this->listenfd);    

}