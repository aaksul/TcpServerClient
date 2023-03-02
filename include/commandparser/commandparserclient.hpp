#include "commandparser.hpp"

class CommandParserClient : public CommandParser 
{
private:

    int ArgumentCheck(int,const char**);
    static constexpr int argc_limit_=5;
    ArgumentPattern pattern_{"-a","-p"};
public:
    virtual ~CommandParserClient(){}
    virtual void Parse(int argc, const char** argv,void*);
    int get_argc_limit() {
        return argc_limit_;
    }
    ArgumentPattern get_pattern() {
        return pattern_;
    }

    
};

