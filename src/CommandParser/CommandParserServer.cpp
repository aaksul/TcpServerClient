#include"CommandParserServer.hpp"
#include"TcpServer.hpp"
#include<iostream>
#include<cstring>
#include<arpa/inet.h>
#include<cstdlib>

enum StatusCode {
    MISSINGARGUMENT=1,
    WRONGIPFORMAT=2,
    WRONGPORTFORMAT=3,

};

void CommandParserServer::Parse(int argc,const char** argv,void* object){
    
    int status=argumentCheck(argc,argv);
    TcpServer** server = static_cast<TcpServer**>(object);
    
    switch (status)
    {
    case StatusCode::MISSINGARGUMENT:
        *server=nullptr;
        std::cout << "missing argument, usage: -a <XXX.XXX.XXX.XXX> -p <0-65535>\n";
        return;
    case StatusCode::WRONGIPFORMAT:
        *server=nullptr;
        std::cout << "wrong ip address\n";
        return;
    case StatusCode::WRONGPORTFORMAT:
        *server=nullptr;
        std::cout << "wrong port format\n";
        return;
    }
    u_int32_t ip;
    inet_pton(AF_INET,argv[2],&ip);
    u_int16_t port = std::atoi(argv[4]);
    setTcpServer(**server,ip,port);
    

}


int CommandParserServer::argumentCheck(int argc,const char** argv){

    if(argc!=CommandParserServer::argcLimit){
        return 1;
    }
    
    if(strcmp(argv[1],pattern.adrOption) || strcmp(argv[3],pattern.portOption)){
        return 1;
    }
    unsigned char ip_add[4]{};
    if(inet_pton(AF_INET,argv[2],ip_add)==0){
        return 2;
    }

    if( std::atoi(argv[4])==0 || (std::atoi(argv[4])>65536) ){
        return 3;
    }
    
    
    return 0;
};