#include<iostream>
#include<tcpclient.hpp>
#include<string>
#include<cstdlib>
#include"commandparserclient.hpp"
#include"tcpsocketclient.hpp"
int main(int argc, char const *argv[])
{

    std::shared_ptr<CommandParserClient> cmd_parser = std::make_shared<CommandParserClient>();
    std::shared_ptr<TcpClient> tcp_client=std::make_shared<TcpClient>();
    cmd_parser->Parse(argc,argv,static_cast<void*>(&tcp_client));
    if(tcp_client==nullptr)
        return 1;
    tcp_client->InitializeSocket(std::make_shared<TcpSocketClient>());
    tcp_client->Connect(std::make_shared<TcpSocketClient>());
    tcp_client->Close(std::make_shared<TcpSocketClient>());
    return 0;
}
