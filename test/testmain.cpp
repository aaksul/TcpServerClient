
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "commandparsertest/commandparsertest.hpp"
#include "tcpsocket/tcpsockettest.hpp"
#include "tcpclient/tcpclienttest.hpp"
int main(int argc, char *argv[])
{
    
    ::testing::InitGoogleMock(&argc,argv);
    return RUN_ALL_TESTS();
}

