#pragma once
#include<unistd.h>
#include<sys/socket.h>

class TcpSocketI  
{
    protected:
    public:
        virtual int SocketInit()=0;
        virtual int Close(int sockfd)=0;
        //virtual int Read(int read_fd,void* buf,size_t count)=0;
        //virtual int Write()=0;
        virtual ~TcpSocketI(){}
    
};


class TcpSocket : public TcpSocketI
{
    protected:
    public:
        int SocketInit() override {return socket(AF_INET,SOCK_STREAM,0);}
        //int Read(int read_fd,void* buff,size_t count){return (read(read_fd,buff,count)); }
        //int Write(){}
        int Close(int sockfd) override {return close(sockfd);}
    
};