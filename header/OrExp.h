//OrExp.h

#ifndef _OREXP_H_
#define _OREXP_H_

//#include "../header/Executor.h"
//#include "../header/Token.h"
#include "../header/ConnectorExp.h"
//#include "../header/Tokenizer.h"
//#include "../header/Expression.h"
#include <string>
#include <iostream>
#include <vector>

class OrExp: public ConnectorExp{
			
	public:
	 //make sure there is an or in main.cpp
		OrExp(Expression* left, Expression* right){ 

			lside =left;
			rside = right;
		}
			/*
			int count =0;
			std::vector<Token*> diff;
			Tokenizer tkz;
			std::string convert = "";
			 diff = tkz.separatingCommand(input);
			for(int i=0; i < diff.size()-1; i++) {
			convert += diff.at(i)->stringify();
			}

			for(int i=0; i < convert.size(); i++) {

			// Update count if we see an ||
			if (convert.at(i) == '|' && convert.at(i+1) == '|') {	
			count = i+1;
			}

			// Keep pushing back into lside
			// as long as there isn't an ||
			if (count == 0) {
				lside.push_back(diff.at(i));
			}

			// If i happens after the second | in an ||,
			// push back into rside instead
			else {
				rside.push_back(dif.at(i));
			}
			}
			*/
		
		std::string stringify(){

		return "or i guess";
	}


	bool evaluate(){

		bool l_succeeded = lside->evaluate();
		bool r_succeeded = false;

		if(!l_succeeded){
			r_succeeded = rside->evaluate();
		}

		return (l_succeeded) 
		|| (r_succeeded);

	}

	private:
		Expression* lside;
		Expression* rside; 


};

#endif
