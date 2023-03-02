#include"commandparserserver.hpp"
#include"tcpserver.hpp"
#include<iostream>
#include<cstring>
#include<arpa/inet.h>
#include<cstdlib>

enum StatusCode {
    kMissingArgument=1,
    kWrongIpFormat=2,
    kWrongPortFormat=3,

};

void CommandParserServer::Parse(int argc,const char** argv,void* object){
    
    TcpServer** server = static_cast<TcpServer**>(object);
    int status=ArgumentCheck(argc,argv);
    
    switch (status)
    {
    case StatusCode::kMissingArgument:
        *server=nullptr;
        std::cout << "missing argument, usage: -a <XXX.XXX.XXX.XXX> -p <0-65535>\n";
        return;
    case StatusCode::kWrongIpFormat:
        *server=nullptr;
        std::cout << "wrong ip address\n";
        return;
    case StatusCode::kWrongPortFormat:
        *server=nullptr;
        std::cout << "wrong port format\n";
        return;
    }

    u_int32_t ip{};
    inet_pton(AF_INET,argv[2],&(ip));
    (*server)->ip(ip);
    (*server)->port(std::atoi(argv[4]));
    

}

int CommandParserServer::ArgumentCheck(int argc,const char** argv){
    int argc_limit=get_argc_limit();
    ArgumentPattern pattern=get_pattern();
    if(argc!=argc_limit){
        return 1;
    }
    
    if(strcmp(argv[1],pattern.adr_option) || strcmp(argv[3],pattern.port_option)){
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
}

