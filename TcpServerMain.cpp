
#include<iostream>
#include<TcpServer.hpp>
#include"CommandParserServer.hpp"
#include<memory>
int main(int argc, char const *argv[])
{

    std::shared_ptr<CommandParser> cmdParser=std::make_shared<CommandParserServer>(); 
    std::shared_ptr<TcpServer> tcpserver=std::make_shared<TcpServer>();
    cmdParser->Parse(argc,argv,static_cast<void*>(&tcpserver));    
    if(tcpserver==nullptr){
        return 1;
    }
    tcpserver->Listen(1500);
    while(1){
        tcpserver->Accept();
    }

    return 0;
}
