#pragma once
#include<string>


class TcpClient
{
private:
    int confd;
public:
    TcpClient(/* args */);
    ~TcpClient();
    void Connect(int,std::string);
    void Write();
};