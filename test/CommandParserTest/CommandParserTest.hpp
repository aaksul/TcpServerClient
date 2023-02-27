#pragma once

#include"gtest/gtest.h"
#include"gmock/gmock.h"
#include"CommandParserServer.hpp"
#include"TcpServer.hpp"
#include<memory>


struct argcv{
    int argc;
    const char** argv;
};

class CommandParserTest2: public testing::TestWithParam<argcv>{
    public:
    std::shared_ptr<TcpServer> tcpserver{new TcpServer()};
    CommandParserServer cmdParse;

};

TEST_P(CommandParserTest2,setNullTest){
    argcv Param=GetParam();

    cmdParse.Parse(Param.argc,Param.argv,static_cast<void*>(&tcpserver));

    ASSERT_THAT(tcpserver,testing::IsNull()) << "its wrong";
}

argcv testC1{1,{}};
testC1.argv={"new","asd","xxxx","--","-d"};
INSTANTIATE_TEST_SUITE_P(CommandParseWithP,
                        CommandParserTest2,
                        testing::Values<argcv>(testC1));

class CommandParserTest : public ::testing::Test{
    protected:



    std::shared_ptr<TcpServer> tcpserver{new TcpServer()};
    CommandParserServer cmdParse;
};

TEST_F(CommandParserTest,CommandParserReturnNullbyMissingArg)
{
    

    constexpr int argc=2;
    const char* argv[argc]={"new"};

    cmdParse.Parse(argc,argv,static_cast<void*>(&tcpserver));

    ASSERT_THAT(tcpserver,testing::IsNull()) << "its wrong";


}

TEST_F(CommandParserTest,CommandParserReturnNullbyWrongOption)
{
    

    constexpr int argc=5;
    const char* argv[argc]={"new","asd","xxxx","--","-d"};

    cmdParse.Parse(argc,argv,static_cast<void*>(&tcpserver));

    ASSERT_THAT(tcpserver,testing::IsNull()) << "its wrong";


}


TEST_F(CommandParserTest,CommandParserReturnNullbyWrongIP)
{
    
    constexpr int argc=5;
    const char* argv[argc]={"TcpServerMain","-a","192.1628.1.1","-p","6222"};

    cmdParse.Parse(argc,argv,static_cast<void*>(&tcpserver));

    ASSERT_THAT(tcpserver,::testing::IsNull()) << "its wrong";


}

TEST_F(CommandParserTest,CommandParserReturnNullbyWrongPort)
{
    
    constexpr int argc=5;
    const char* argv[argc]={"TcpServerMain","-a","192.168.1.1","-p","622200"};

    cmdParse.Parse(argc,argv,static_cast<void*>(&tcpserver));

    ASSERT_THAT(tcpserver,::testing::IsNull()) << "its wrong";


}

TEST_F(CommandParserTest,CommandParserSetServerObject)
{
    
    constexpr int argc=5;
    const char* argv[argc]={"TcpServerMain","-a","192.168.1.1","-p","6222"};

    cmdParse.Parse(argc,argv,static_cast<void*>(&tcpserver));

    ASSERT_THAT(tcpserver,::testing::NotNull()) << "its wrong";

    



}
