#ifndef __PARSING_TEST__
#define __PARSING_TEST__


#include "gtest/gtest.h"
#include "../header/Tokenizer.h"
//#include "../src/Tokenizer.cpp"
#include <iostream>


std::vector<Token*>exTesting;
//exTesting.push_back("ls");
//exTesting.push_back("s");
//exTesting.push_back("-");  
//exTesting.push_back("a");
	

TEST(parsingTest, testingLS) {
	std::string testPLSwork = "ls -a";
	std::string arr[2] = {"ls", "-a"}; 
	Tokenizer val;
	std::vector<Token*> tokens = val.ExecuteSeparatingCommand(testPLSwork);
	
	for (int i=0; i< tokens.size()-1; i++) {
            std::cout << tokens[i]->stringify() << std::endl;
  }
	    std::cout << "tokens.size(): " << tokens.size() << std::endl
                 << "arr.size:      " << 2 << std::endl;
	
	// loop the correct amount of times
	for(int i=0; i<2; i++) {

		/*if (tokens[i] == nullptr) {
			std::cout << "We found a nullptr at tokens[" << i << "]." << std::endl;
		}*/

		//std::cout << "tokens[" << i << "]: \"" << tokens[i] << "\"" << std::endl;
		EXPECT_EQ(tokens[i]->stringify(), arr[i]);
	}	
}


TEST(parsingTest2, testingLS2) {
        std::string testPLSwork2 = "echo A && echo B";
        std::string arr2[5] = {"echo", "A", "&&", "echo", "B"};
        Tokenizer val2;
        std::vector<Token*> tokens2 = val2.ExecuteSeparatingCommand(testPLSwork2);

        for (int i=0; i< tokens2.size()-1; i++) {
            std::cout << tokens2[i]->stringify() << std::endl;
        }
            std::cout << "tokens2.size(): " << tokens2.size() << std::endl
                  << "arr2.size:      " << 5 << std::endl;

        // loop the correct amount of times
        for(int i=0; i<5; i++) {
        	/*if (tokens2[i] == nullptr) {
                std::cout << "We found a nullptr at tokens2[" << i << "]." << std::endl;
           	}*/

          	//std::cout << "tokens2[" << i << "]: \"" << tokens2[i] << "\"" << std::endl;
                EXPECT_EQ(tokens2[i]->stringify(), arr2[i]);
        }
   
}

TEST(parsingTest3, testingLS3) {
        std::string testPLSwork3 = "echo A # && echo B";
        std::string arr3[6] = {"echo", "A", "#", "&&", "echo", "B"};
        Tokenizer val3;
        std::vector<Token*> tokens3 = val3.ExecuteSeparatingCommand(testPLSwork3);

        for (int i=0; i< tokens3.size()-1; i++) {
            std::cout << tokens3[i]->stringify() << std::endl;
        }
            std::cout << "tokens3.size(): " << tokens3.size() << std::endl
                  << "arr3.size:      " << 6 << std::endl;

        // loop the correct amount of times
         for(int i=0; i<6; i++) {
              /* if (tokens3[i] == nullptr) {
                 std::cout << "We found a nullptr at tokens3[" << i << "]." << std::endl;
               }*/
               //std::cout << "tokens3[" << i << "]: \"" << tokens3[i] << "\"" << std::endl;
               EXPECT_EQ(tokens3[i]->stringify(), arr3[i]);
        }
}


TEST(parsingTest4, testingLS4) {
        std::string testPLSwork4 =  "echo \"A || exit\"";
        std::string arr4[2] = {"echo", "A || exit"};

        Tokenizer val4;
        std::vector<Token*> tokens4 = val4.ExecuteSeparatingCommand(testPLSwork4);

        for (int i=0; i< tokens4.size()-1; i++) {
            std::cout << tokens4[i]->stringify() << std::endl;
        }
            std::cout << "tokens4.size(): " << tokens4.size() << std::endl
                  << "arr4.size:      " << 2 << std::endl;


	for(int i=0; i<2; i++) {
	
        	EXPECT_EQ(tokens4[i]->stringify(), arr4[i]);
	}
}


//for(int i = 0; i<exTesting.size(); i++) {
//       cout << exTesting.at(i);
//}

#endif

