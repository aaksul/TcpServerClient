#include<iostream>
#include<TcpClient.hpp>
#include<string>
#include<cstdlib>
int main(int argc, char const *argv[])
{

    if(argc != 3){
        std::cout << "usage <port> <ip_address>" << std::endl;
        return 1;
    }
    const std::string port = argv[1];
    const std::string ip_address = argv[2];

    int port_int = atoi(port.c_str());

    TcpClient tcpclient;

    tcpclient.Connect(port_int,ip_address);
    tcpclient.Write();
    return 0;
}
