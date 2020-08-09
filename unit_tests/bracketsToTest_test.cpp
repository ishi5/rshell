#ifndef __BRACKETSTOTEST_TEST__
#define __BRACKETSTOTEST_TEST__


#include "gtest/gtest.h"
#include "../header/Tokenizer.h"
//#include "../src/Tokenizer.cpp"
#include <iostream>


//std::vector<Token*>exParenVec;
//exTesting.push_back("ls");
//exTesting.push_back("s");
//exTesting.push_back("-");  
//exTesting.push_back("a");
	

TEST(convertBracketsTest, testingBrackets) {
	std::string bracketsInput = "[ -e .gitignore ]";
	std::string arr[3] = {"test", "-e", ".gitignore"}; 
	Tokenizer v;
	std::vector<Token*> tokens = v.ExecuteSeparatingCommand(bracketsInput);
	
	for (int i=0; i< tokens.size()-1; i++) {
            std::cout << tokens[i]->stringify() << std::endl;
  }
	    std::cout << "tokens.size(): " << tokens.size() << std::endl
                 << "arr.size:      " << 3 << std::endl;
	
	// loop the correct amount of times
	for(int i=0; i<2; i++) {

		/*if (tokens[i] == nullptr) {
			std::cout << "We found a nullptr at tokens[" << i << "]." << std::endl;
		}*/

		//std::cout << "tokens[" << i << "]: \"" << tokens[i] << "\"" << std::endl;
		EXPECT_EQ(tokens[i]->stringify(), arr[i]);
	}	
}


#endif
