#pragma once

class CommandParser
{
private:
public:
    virtual void Parse(int,const char**,void*){}
    virtual ~CommandParser(){}
};

