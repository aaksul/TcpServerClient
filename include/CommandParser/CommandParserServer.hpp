#pragma once

#include"CommandParser.hpp"
#include<string>
class CommandParserServer : public CommandParser
{
private:
    int argumentCheck(int argc,const char** argv);
    
public:
    
    /*
    Set Server Object with arguments values
    TcpServerMain -a 192.168.0.1 -p 2222 
    */
    virtual void Parse(int argc,const char** argv,void* object);
private:
    static constexpr int argcLimit=5;

    struct ArgumentPattern
    {
        const char* adrOption;
        const char* portOption;
    }pattern={"-a","-p"};
     
    
};

