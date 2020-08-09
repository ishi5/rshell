
#ifndef _LEAF_H
#define _LEAF_H

#include "../header/Executor.h"
//#include "../header/Token.h"
//#include "../header/Tokenizer.h"
#include <string>
#include<iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include "../header/Expression.h"

class Leaf: public Expression{

	public:

		Leaf(Token* l){

			lf = l;
		}
					

		std::string stringify(){

			return "leaf i guess";
		}
					
		std::vector<char*> LeafTokenVectortocharArray (std::vector<Token*> v){

			std::vector<char*> token_cstrs;
			
			for(unsigned i=0; i<v.size() && v[i] != nullptr;++i){

			    	char* temp = new char[v[i]->stringify().size() + 1]; // +1 for null terminator

			    	strcpy(temp,v[i]->stringify().data());
			    	token_cstrs.push_back(temp); 
			}

			return token_cstrs;
		}




		bool evaluate(){

		//return lf->evaluate();
			Tokenizer svector;
			std:: vector<Token*> converter;
			converter = svector.ExecuteSeparatingCommand(lf->stringify());
			std::vector<Token*> leafTemp;
			//leafTemp.push_back(lf);

			std::vector<char*> exinput = LeafTokenVectortocharArray(converter);
			Executor ex;
			//ex.execute(exinput[0], exinput.data());
			if(ex.execute(exinput[0], exinput.data())){
				for(int i =0; i<exinput.size(); i++) {
					if (exinput[i] != nullptr){
						delete [] exinput[i];
				
					}
				}

				return false;
			}
			else{
				for(int i =0; i<exinput.size(); i++) {
					if (exinput[i] != nullptr){
						delete [] exinput[i];
				
					}
				}

				return true;
			}
					
		}
	//	private:
	Token* lf;

};

#endif
