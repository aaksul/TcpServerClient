#pragma once

#include"commandparser.hpp"
#include<string>
class CommandParserServer : public CommandParser
{
    
public:
    
    /*
    Set Server Object with arguments values
    TcpServerMain -a 192.168.0.1 -p 2222 
    */
    virtual void Parse(int argc,const char** argv,void* object) override;
private:
    int get_argc_limit() { return argc_limit_;}
    ArgumentPattern get_pattern() {return pattern_;}
    int ArgumentCheck(int,const char**);
    int argc_limit_=5;
    ArgumentPattern pattern_={"-a","-p"};
     
    
};

