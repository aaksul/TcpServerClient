
#include<iostream>
#include<tcpserver.hpp>
#include"commandparserserver.hpp"
#include"tcpsocketserver.hpp"
#include<memory>
int main(int argc, char const *argv[])
{

    std::shared_ptr<CommandParser> cmd_parser=std::make_shared<CommandParserServer>(); 
    std::shared_ptr<TcpServer> tcp_server=std::make_shared<TcpServer>();
    std::shared_ptr<TcpSocketServer> tcp_socket_server=std::make_shared<TcpSocketServer>();
    
    cmd_parser->Parse(argc,argv,static_cast<void*>(&tcp_server));    
    if(tcp_server==nullptr){
        return 1;
    }

    tcp_server->InitializeSocket(tcp_socket_server);
    
    tcp_server->Listen(tcp_socket_server);
    while (true)
    {
        tcp_server->Accept(tcp_socket_server);
    }
    
    

    return 0;
}
