
#include<iostream>
#include<TcpServer.hpp>

int main(int argc, char const *argv[])
{
    std::cout<< "Hello world\n";
    TcpServer tcpserver;
    tcpserver.Listen(1500);
    while(1){
        tcpserver.Accept();
    }

    return 0;
}
