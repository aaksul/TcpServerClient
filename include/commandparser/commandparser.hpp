#pragma once
#include"arpa/inet.h"
#include<cstring>
#include<cstdlib>
struct ArgumentPattern
{
    const char* adr_option;
    const char* port_option;
};

class CommandParser
{
    
protected:



public:
    virtual void Parse(int argc,const char** argv,void* object)=0;
    virtual ~CommandParser(){};
};

