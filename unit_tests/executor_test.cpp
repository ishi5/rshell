#ifndef __EXECUTOR_TEST_CPP__
#define __EXECUTOR_TEST_CPP__


#include "gtest/gtest.h"
#include "../header/Tokenizer.h"
//#include "../src/Tokenizer.cpp"
#include "../header/CommandToken.h"
#include "../header/Executor.h"
#include "../src/Executor.cpp"
#include "../header/ConnectorToken.h" 
#include <iostream>


TEST(InvalidWordTest, ExecTest) {
	char** args = new char*[5];
	Executor validOrNot;
	args[0] = (char*) "hel;l";
	args[1] = nullptr;
	EXPECT_EQ(validOrNot.execute(args[0], args), 1);
}

TEST(ValidWordTest2, ExecTest2) {
        char** args2 = new char*[5];
        Executor validOrNot2;
        args2[0] = (char*) "ls";
	args2[1] = nullptr;
        EXPECT_EQ(validOrNot2.execute(args2[0], args2), 0);
}

TEST(InvalidWordTest3, ExecTest3) { 
        char** args3 = new char*[5];
        Executor validOrNot3;
        args3[0] = (char*) "echor";
	args3[1] = (char*) "sleep";
        args3[2] = nullptr;
        EXPECT_EQ(validOrNot3.execute(args3[0], args3), 1);
}

#endif
