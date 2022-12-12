#include<iostream>
#include<TcpClient.hpp>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<string>
#include<unistd.h>
TcpClient::TcpClient(){

}

TcpClient::~TcpClient(){
    std::cout<<"Closed socket";
    close(confd);
}

void TcpClient::Connect(int port, std::string ip_address){

    int sockfd = socket(AF_INET,SOCK_STREAM,0);

    if( sockfd < 0 )
        std::cout << "Error in TcpClient socket";

    
    struct in_addr ip_addr;

    if(inet_aton(ip_address.c_str(),&ip_addr)==0){
        std::cout<< "Invalid Address";
        //exit();
    }
    struct sockaddr_in addr;

    addr.sin_family=AF_INET;
    addr.sin_port=htons(port);
    addr.sin_addr=ip_addr;

    connect(sockfd,(struct sockaddr*)&addr,sizeof(addr));
    confd=sockfd;
}

void TcpClient::Write(){
    std::string buffer;

    while(1){
        std::getline(std::cin,buffer);
        write(confd,buffer.c_str(),buffer.size());
    }
}
