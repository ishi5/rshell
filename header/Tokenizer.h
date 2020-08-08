#ifndef _TOKENIZER_H_
#define _TOKENIZER_H_

#include <stdio.h>
#include <string>
#include <vector>
#include "../header/Token.h"
#include "../header/Expression.h"
class Tokenizer{

        private:
        std::string userInput;
		std::vector<Token*> store;
		std::vector<Token*> executeStore;
		//char userInput;
		
        public:
		Tokenizer();
		~Tokenizer();
		Tokenizer(const std::string& str);
		void parsing(std::vector<char>usedforparse);
		std::vector<Token*> separatingCommand(std::string);
		std::vector<Token*> infixtoprefix(std::vector<Token*>);

		std::vector<Token*> ExecuteSeparatingCommand(std::string);
		void ExecuteParsing(std::vector<char>usedforparse);
		Expression* buildTree(std::vector<Token*> v, int &i);
		
		//helper functions
		Expression* getTree();
		std::string checker(std::string c);


};

#endif
