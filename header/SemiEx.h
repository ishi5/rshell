//SemiExp.

#ifndef _SEMIEXP_H
#define _SEMIEXP_H

//#include "../header/Executor.h"
//#include "../header/Token.h"
#include "../header/ConnectorExp.h"
//#include "../header/Tokenizer.h"
//#include "../header/Expression.h"
#include <string>
#include<iostream>
#include <vector>
class SemiExp: public ConnectorExp{
			
				public:
		 //make sure there is an or in main.cpp

							SemiExp(Expression* left, Expression* right){ 

							lside =left;
							rside = right;

						
						/*int count =0;
						std::vector<Token*> diff;
						Tokenizer tkz;
						std::string convert = "";
						 diff = tkz.separatingCommand(input);
						for(int i=0; i < diff.size()-1; i++) {
							convert += diff.at(i)->stringify();
						}

						for(int i=0; i < convert.size(); i++) {

							// Update count if we see an ||
							if (convert.at(i) ';') {	
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
						}*/
					}
						std::string stringify(){

							return "semi i guess";
						}
						bool evaluate(){

								lside->evaluate();

								return rside->evaluate();

							}


				private:
						Expression* lside;
						Expression* rside; 


};

#endif
