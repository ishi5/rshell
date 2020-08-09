
#include <vector>
#include <iostream>
#include <cstring>
#include "../header/UserInput.h"
#include "../header/CommandToken.h"
#include "../header/ConnectorToken.h"
#include "../header/Tokenizer.h"
// #include "../src/Tokenizer.cpp"
#include "../header/Executor.h"
#include <algorithm>

/*std::vector<char*> TokenVectortocharArray (std::vector<Token*> v){

	std::vector<char*> token_cstrs;
	
    for(unsigned i=0; i<v.size() && v[i] != nullptr;++i){

    	char* temp = new char[v[i]->stringify().size() + 1]; // +1 for null terminator

    	strcpy(temp,v[i]->stringify().data());
    	token_cstrs.push_back(temp); 
	}

        return token_cstrs;
}*/


int main(){

	std::string check=" ";

	do {
		UserInput read;
		std:: string inputstr;
		Tokenizer tokenizer;
			
		read.printCommand();

		inputstr = read.readInput();
		check +=inputstr;
		if(inputstr== "exit"){

				break;
			}

		else{
				//std:: vector<Token*> converter;
				//converter = tokenizer.ExecuteSeparatingCommand(inputstr);
				//converter = tokenizer.separatingCommand(inputstr);
				tokenizer.separatingCommand(inputstr);

				/*std::vector<char*> exinput = TokenVectortocharArray(converter);
				Executor ex;
				ex.execute(exinput[0], exinput.data());
				for(int i =0; i<exinput.size(); i++) {
					if (exinput[i] != nullptr){
						delete [] exinput[i];
				
					}
				}

				*/

				Expression* root = tokenizer.getTree();
				root->evaluate();
		}


	} while(check!="exit"); //true

	return 0;
}
		
