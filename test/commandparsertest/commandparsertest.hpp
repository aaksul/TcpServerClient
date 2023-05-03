#pragma once

#include"gtest/gtest.h"
#include"gmock/gmock.h"
#include"commandparserserver.hpp"
#include"tcpserver.hpp"
#include<memory>
#include"tcpclient.hpp"
#include"commandparserclient.hpp"

using namespace testing;

struct ArgcArgv{
    int argc;
    const char** argv;
};


class CommandParserServerTest: public TestWithParam<ArgcArgv>{
    

    public:
        std::shared_ptr<TcpServer> tcp_server_{new TcpServer()};
        CommandParserServer cmd_parse_;

};

TEST_P(CommandParserServerTest,NullOnOutParamTest){
    ArgcArgv Param=GetParam();

    cmd_parse_.Parse(Param.argc,Param.argv,static_cast<void*>(&tcp_server_));

    ASSERT_THAT(tcp_server_,IsNull()) << "its wrong";
}


const char* argvC1[]={"new"};
ArgcArgv testC1{2,argvC1};
const char* argvC2[]={"new","asd","xxxx","--","-d"};
ArgcArgv testC2{5,argvC2};
const char* argvC3[]={"TcpServerMain","-a","192.1628.1.1","-p","6222"};
ArgcArgv testC3{5,argvC3};
const char* argvC4[]={"TcpServerMain","-a","192.168.1.1","-p","622200"};
ArgcArgv testC4{5,argvC4}; 

INSTANTIATE_TEST_CASE_P(NullCheckTests,
                        CommandParserServerTest,
                        Values<ArgcArgv>(testC1,testC2,testC3,testC4));




class CommandParserServerTest2 : public ::Test{
    protected:
        std::shared_ptr<TcpServer> tcp_server_{new TcpServer()};
        CommandParserServer cmd_parse_;
};


TEST_F(CommandParserServerTest2,CommandParserSetServerObject)
{
    constexpr int argc=5;
    const char* argv[argc]={"TcpServerMain","-a","192.168.1.2","-p","6222"};

    cmd_parse_.Parse(argc,argv,static_cast<void*>(&tcp_server_));

    ASSERT_THAT(tcp_server_,NotNull()) << "its wrong";
    ASSERT_THAT(*tcp_server_,Property(&TcpServer::port,Eq((u_int16_t)6222)));
    ASSERT_THAT(*tcp_server_,Property(&TcpServer::ip,Eq((u_int32_t)(0x0201A8C0))));
}

class CommandParserClientTest: public TestWithParam<ArgcArgv>{
    

    public:
        std::shared_ptr<TcpClient> tcp_client_{new TcpClient()};
        CommandParserClient cmd_parse_;

};

TEST_P(CommandParserClientTest,NullOnOutParamTest){
    ArgcArgv Param=GetParam();

    cmd_parse_.Parse(Param.argc,Param.argv,static_cast<void*>(&tcp_client_));

    ASSERT_THAT(tcp_client_,IsNull()) << "its wrong";
}


const char* argv_c_C1[]={"new"};
ArgcArgv test_c_C1{2,argvC1};
const char* argv_c_C2[]={"new","asd","xxxx","--","-d"};
ArgcArgv test_c_C2{5,argvC2};
const char* argv_c_C3[]={"TcpServerMain","-a","192.1628.1.1","-p","6222"};
ArgcArgv test_c_C3{5,argvC3};
const char* argv_c_C4[]={"TcpServerMain","-a","192.168.1.1","-p","622200"};
ArgcArgv test_c_C4{5,argvC4};

INSTANTIATE_TEST_SUITE_P(NullCheckTests,
                        CommandParserClientTest,
                        Values<ArgcArgv>(test_c_C1,test_c_C2,test_c_C3,test_c_C4));




class CommandParserClientTest2 : public ::Test{
    protected:
        std::shared_ptr<TcpServer> tcp_client_{new TcpServer()};
        CommandParserServer cmd_parse_;
};

TEST_F(CommandParserClientTest2,CommandParserSetClientObject)
{
    constexpr int argc=5;
    const char* argv[argc]={"TcpServerMain","-a","192.168.1.2","-p","6222"};

    cmd_parse_.Parse(argc,argv,static_cast<void*>(&tcp_client_));

    ASSERT_THAT(tcp_client_,NotNull()) << "its wrong";
    ASSERT_THAT(*tcp_client_,Property(&TcpServer::port,Eq((u_int16_t)6222)));
    ASSERT_THAT(*tcp_client_,Property(&TcpServer::ip,Eq((u_int32_t)(0x0201A8C0))));
}