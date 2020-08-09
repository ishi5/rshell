#include "../header/Tokenizer.h"
//#include "../header/Token.h"
//#include "../header/UserInput.h"
#include <vector>
#include "../header/CommandToken.h"
#include "../header/ConnectorToken.h"
#include "../header/ArgToken.h"
#include "../header/AndToken.h"
#include "../header/OrToken.h"
#include "../header/ExitToken.h"
//#include "../header/Expression.h"
#include "../header/leftParToken.h"
#include "../header/rightParToken.h"
#include "../header/SemiToken.h"
#include "../header/TestToken.h"
#include <stack>
#include <algorithm>
//ADDED FOR EXPTREE
#include "../header/Leaf.h"
#include "../header/AndExp.h"
#include "../header/OrExp.h"
#include "../header/SemiEx.h"
//#include "../header/ConnectorExp.h"
#include "../header/CommandToken.h"

#include <iostream>
#include <string>



Tokenizer::Tokenizer(){
	userInput = "";
}


Tokenizer::~Tokenizer(){
        store.clear();
}

Tokenizer::Tokenizer(const std::string& str){
	
	userInput=str;
	//parsing(userInput, argv);
}


Expression* Tokenizer::buildTree(std::vector<Token*> v, int &i){

	//Token thisToken = v[i];
    CommandToken* c = dynamic_cast<CommandToken*> (v[i]);	
	if(c!=nullptr){
		return new Leaf(v[i]);
	}

	else{
		  AndToken* a = dynamic_cast<AndToken*> (v[i]);	
		  OrToken* o = dynamic_cast<OrToken*> (v[i]);	
		  SemiToken* s = dynamic_cast<SemiToken*> (v[i]);	
		  if(a!=nullptr){
		   	Expression* root = new AndExp(buildTree(v, ++i),buildTree(v, ++i));
		   	return root; 
		
	      }

	    else if(o!=nullptr){
			Expression* root = new OrExp(buildTree(v, ++i),buildTree(v, ++i));
			return root; 
		}
		else{
			Expression* root = new SemiExp(buildTree(v, ++i),buildTree(v, ++i));
			return root; 
		}
		//Expression* root = new ConnectorExp(v[i]);

		//root->lside = buildTree(v, ++i);
		//root ->rside = buildTree(v, ++i);
	}
}


std::vector<Token*> Tokenizer::infixtoprefix(std::vector<Token*> tok){

	std::stack<Token*> mystack;
	std::vector<Token*> vec;
	Token* stacktop;

	std::reverse(tok.begin(),tok.end());

	// Before shunting yard,
	// swap the ) with (
	for (int i = 0; i < tok.size(); i++) {

		leftParToken*  lp = dynamic_cast<leftParToken*> (tok[i]);
		rightParToken* rp = dynamic_cast<rightParToken*>(tok[i]);

		// If you see a left parenthesis,
		// make it a right parenthesis
		if (lp) {

			delete tok[i];
			tok[i] = new rightParToken(")");
		}

		// Or, do the converse
		if (rp) {

			delete tok[i];
			tok[i] = new leftParToken("(");
		}

	}

	for(int i=0; i<tok.size(); i++){

		// while(tok[i]!='\0'){

			AndToken* a = dynamic_cast<AndToken*> (tok[i]);
			OrToken* o = dynamic_cast<OrToken*> (tok[i]);
			SemiToken* s = dynamic_cast<SemiToken*> (tok[i]);
			leftParToken* lp = dynamic_cast<leftParToken*> (tok[i]);
			rightParToken* rp = dynamic_cast<rightParToken*> (tok[i]);
			


			//if equal to null pointer, dont push back
			//if connector token
			if(a!=nullptr|| o!=nullptr|| s!=nullptr || lp!=nullptr){
					mystack.push(tok[i]);
			}

			else if(rp!=nullptr){
				//while(mystack.top()!= lp){
				leftParToken* lp2 = dynamic_cast<leftParToken*> (mystack.top());

				while(lp2 == nullptr) {
					stacktop = mystack.top();
					vec.push_back(stacktop->clone());
					mystack.pop();

					lp2 = dynamic_cast<leftParToken*> (mystack.top());
				}
				if(lp2!= nullptr){
					mystack.pop();
				}
			  
			}

			// number / leaf, e.g. echo A
			else{

				vec.push_back(tok[i]);
			}
		// }


	}

	while(!mystack.empty()){

		stacktop = mystack.top(); 
		vec.push_back(stacktop->clone());
		mystack.pop();

	}

	std::reverse(vec.begin(), vec.end());

return vec;


}



std::string Tokenizer::checker(std::string checkInput){

	std::string space = " ";

	for(int i = 0; i<checkInput.size(); i++) {
		if( (checkInput.at(i) == '(') && (checkInput.at(i+1) != ' ') ) {
				checkInput.insert(i+1, space);
		}
		else if( (checkInput.at(i) == ')') && (checkInput.at(i-1) != ' ') ) {
				checkInput.insert(i, space);
		}
		if( (checkInput.at(i) == '[') && (checkInput.at(i+1) != ' ') ) {
				checkInput.insert(i+1, space);
		}
		else if( (checkInput.at(i) == ']') && (checkInput.at(i-1) != ' ') ) {
				checkInput.insert(i, space);
		}

	}
	//std::cout << "returning from string checker : \"" << checkInput << "\"" << std::endl;
	return checkInput;

}


//GROUPING TOGETHER!!!"ECHO A"
std::vector<Token*> Tokenizer::separatingCommand(std::string inpstring){
	
	// HERE :)
	//call function that check for left paran -> then if theres not a space after left paren then add a space ->same for right paren

	std::string cmstring;
	cmstring = checker(inpstring);


    bool amiquote = false;

    cmstring += ' '; // add this to make sure to tokenize the last token in the string

    //std::cout << "\"" << cmstring << "\"" << std::endl;
	
    std::vector<char> usedForParsing;
    //bool isWord = false;
    //int j=0;
    int i=0;
   

    /*if(cmstring.at(0) == '[') {
    	usedForParsing.push_back('t');
    	usedForParsing.push_back('e');
    	usedForParsing.push_back('s');
    	usedForParsing.push_back('t');
    	usedForParsing.push_back(' ');
    	for(int k=1; k<cmstring.size();++k){
    		if(cmstring.at(k)!=']'){
    			usedForParsing.push_back(cmstring.at(k));
    			j++;
    		}
    	}
    	j= j+2;
		parsing(usedForParsing);
		usedForParsing.clear();
    }

    if(cmstring.at(0) == 't' && cmstring.at(1) == 'e' && cmstring.at(2) == 's' && cmstring.at(3) == 't') {
		for(int j=0; j<cmstring.size();j++) {
			if(cmstring.at(j+1) != '&' && cmstring.at(j+1) != '|' && cmstring.at(j+1) != ';') {
				usedForParsing.push_back(cmstring.at(j));
				j++;
			}
			//else
		}
		j= j+2;
		parsing(usedForParsing);
		usedForParsing.clear();
	}
*/


    for(int i=0 ;i<cmstring.size();i++) {
		//modify for special case where there's quotes"

		if (cmstring.at(i) == '\"') {
			amiquote = !amiquote;
        }
		//while(cmstring!='\n'){
	
	// If it's a non-space char,
	// push it into usedForParsing			
	/*if(cmstring.at(i) != ' ' || amiquote){
        	usedForParsing.push_back(cmstring.at(i));
        }*/

        // If we see a parenthesis
        if(cmstring.at(i) == '(' || cmstring.at(i) == ')') {

        	// This was something with a parenthesis at the end 	// example: echo B )
        	if (!usedForParsing.empty()) {

        		parsing(usedForParsing);
        		usedForParsing.clear();
        	}

    		usedForParsing.push_back(cmstring.at(i));
        	parsing(usedForParsing);
        	usedForParsing.clear();

        	continue;
        }

    	if((cmstring.at(i) != ' ') && (cmstring.at(i) != '&') && (cmstring.at(i) != '|') && (cmstring.at(i) != ';')){
        	usedForParsing.push_back(cmstring.at(i));
        }


       	if(cmstring.at(i) == ' '){
       		if ( i < cmstring.length() - 2 && (cmstring.at(i + 1) == '&' && cmstring.at(i + 2) == '&' && cmstring.at(i-1) != ')')) {
       			parsing(usedForParsing);
       			usedForParsing.clear();
       		}

       		else if ( i < cmstring.length() - 2 && (cmstring.at(i + 1) == '|' && cmstring.at(i + 2) == '|' && cmstring.at(i-1) != ')')) {
       			parsing(usedForParsing);
       			usedForParsing.clear();
       		}

       		else if ( i < cmstring.length() - 2 && (cmstring.at(i + 1) == ';' && cmstring.at(i-1) != ')')) {
       			parsing(usedForParsing);
       			usedForParsing.clear();
       		}

   
		    else {
		       usedForParsing.push_back(cmstring.at(i));
		    }
        }

       if( (cmstring.at(i) == '&'  && cmstring.at(i+1) == '&')) {
      		usedForParsing.push_back(cmstring.at(i));
      		usedForParsing.push_back(cmstring.at(i+1));
      		parsing(usedForParsing);
      		usedForParsing.clear();
        }

        if( cmstring.at(i) == '|'  && cmstring.at(i+1) == '|') {
      		usedForParsing.push_back(cmstring.at(i));
      		usedForParsing.push_back(cmstring.at(i+1));
      		parsing(usedForParsing);
      		usedForParsing.clear();
        }
        if( cmstring.at(i) == ';') {
      		usedForParsing.push_back(cmstring.at(i));
      		parsing(usedForParsing);
      		usedForParsing.clear();
        }

    }

	// Only try to tokenize something
	// if there's a space
	// and if we're not in a quote
        /*else{
		std::string test = "";     
		for(int i = 0; i<usedForParsing.size();++i){
	       		test+= usedForParsing.at(i);
       		}	
		if(test == "||" || test == "&&" || test == ";") {
			isWord == false;
			parsing(usedForParsing, isWord);
		}
		//reach end of connector or end of string
		else {
			if (isWord == true) {	//the input before was commnd/argument
			//make ARGUMENT
				parsing(usedForParsing, isWord);
			}
			else {  // FALSE   --> the input before was a connector
			//make COMMAND
				parsing(usedForParsing, isWord);
				isWord = true;
			}
		}*/

	//usedForParsing.clear();

	if(!usedForParsing.empty()){

    	parsing(usedForParsing);
	}

 std::vector<Token*> storeTemp = infixtoprefix(store);
 store = storeTemp;
 //buildTree(store, 0);
 store.push_back(nullptr);

 return store;
}


Expression* Tokenizer::getTree() {

	int i =0;
	return buildTree(store, i);

}


void Tokenizer::parsing(std::vector<char> cstore){

	std::string type = "";
	std::string temp = "";




	for(int i = 0; i<cstore.size();++i){
		type+= cstore.at(i);
	}
	
	if(type.at(type.size()-1) == ' ') {
		temp = type.substr(0,type.size()-2);
	}

	if(type.at(0) == ' ') {   
   		temp = type.substr(1,type.size()-1);
    }

	else {
		temp = type;
	}

	if (temp.empty() || cstore.empty())
		return;

	
	if(temp == "&&"){

		Token* andTok = new AndToken(temp);
		store.push_back(andTok);
	}
	else if(temp == "||"){
		Token* orTok = new OrToken(temp);
		store.push_back(orTok); 
	}
	else if(temp == ";"){
		Token* semiTok = new SemiToken(temp); //semitok token
		store.push_back(semiTok); 
	}
	else if(temp == "exit") {
		Token* exTok = new ExitToken(temp);
		store.push_back(exTok);
	}

	else if(temp == "("){
		Token* lpTok = new leftParToken(temp);
		store.push_back(lpTok);

		// std::cout << "Just pushed back a lpToken (" << std::endl;

	}

	else if(temp == ")"){
		Token* rpTok = new rightParToken(temp);
		store.push_back(rpTok);

		// std::cout << "Just pushed back a rpTok" << std::endl;

	}
	/*else if (temp.at(0) == 't' && temp.at(1) == 'e' && temp.at(2) == 's' && temp.at(3) == 't') {
		Token* testTok = new TestToken(temp);
		store.push_back(testTok);
	} */	
	else{

		std::string temp2;
		for(int i=0; i<temp.size();++i) {
			if(temp.at(i) != '\"'){
				temp2+= temp.at(i);

			} // If type is a quote,

	// strip it of its quote
		}

		//if(isWord == false) {
		Token* cmmdTok = new CommandToken(temp2);
		store.push_back(cmmdTok); 

		// std::cout << "In Tokenizer::parsing()," << std::endl
		//           << "just pushed back a token with string \"" << temp2 << "\"" << std::endl;
		//}
		//else {//if isWord == true
		//	Token* argTok = new ArgToken(type);
		//	store.push_back(argTok);
	}	
}

//void Tokenizer::stringify()






//EXECUTE FUNCTIONS


// takes "echo A"
// returns "echo" "A" nullptr


//groups SEPARATELY "ECHO" "A"
std::vector<Token*> Tokenizer::ExecuteSeparatingCommand(std::string strString){
	
	std::string cmstring;
	cmstring = checker(strString);


    bool amiquote = false;
   int j=0;
     cmstring += ' '; // add this to make sure to tokenize the last token in the string

    //std::cout << "\"" << cmstring << "\"" << std::endl;
	
    
    std::vector<char> exForParsing;
     std::string temp;

     if(cmstring.at(0) == '[') {
        //exForParsing.push_back('t');
        //exForParsing.push_back('e');
        //exForParsing.push_back('s');
        //exForParsing.push_back('t');
       // exForParsing.push_back(' ');
     	temp += "test";
        for(int k=1; k<cmstring.size();++k){
                if(cmstring.at(k)!=']'){
                        //exForParsing.push_back(cmstring.at(k));
                		temp += cmstring.at(k);
                        //j++;
                }
                // if(cmstring.at(k+1) != nullptr) {
                // 		temp += cmstring.at(k);
                // }
        }
        	//j= j+2;
        	cmstring.clear();
        	cmstring += temp;
               //ExecuteParsing(exForParsing);
                //exForParsing.clear();
    }


   
    for(int i=0 ;i<cmstring.size();i++){
		//modify for special case where there's quotes"

		if (cmstring.at(i) == '\"') {
			amiquote = !amiquote;
        }
		//while(cmstring!='\n'){
	
	// If it's a non-space char,
	// push it into usedForParsing			
		if(cmstring.at(i) != ' ' || amiquote){
        	exForParsing.push_back(cmstring.at(i));

        }

	// Only try to tokenize something
	// if there's a space
	// and if we're not in a quote
        else{
			ExecuteParsing(exForParsing);
			exForParsing.clear();
		}
		

		// exForParsing.clear();
     }

   executeStore.push_back(nullptr);

   return executeStore;
}


void Tokenizer::ExecuteParsing(std::vector<char> cexecuteStore){

	std::string type = "";
	
	for(int i = 0; i<cexecuteStore.size();++i){
	
		type+= cexecuteStore.at(i);
	}


	//if (type.empty() || cexecuteStore.empty())
	//	return;
	
	if(type == "&&"){

	Token* andTok = new AndToken(type);
	executeStore.push_back(andTok);
	

	}

	else if(type == "||"){
	Token* orTok = new OrToken(type);
	executeStore.push_back(orTok); 
	}
	
	else if(type == ";"){
	Token* semiTok = new Connector(type);
	executeStore.push_back(semiTok); 
	}
	else if(type == "exit") {
	Token* exTok = new ExitToken(type);
	executeStore.push_back(exTok);
	}
	else{
		std::string temp;
		for(int i=0; i<type.size();++i) {
			if(type.at(i) != '\"'){
				temp+= type.at(i);

			} // If type is a quote,

			// strip it of its quote
		}

			Token* cmmdTok = new CommandToken(temp);
 			executeStore.push_back(cmmdTok); 
 	}
	

}
