#ifndef _USER_INPUT_H_
#define _USER_INPUT_H_

#include <string>
#include <iostream>
#include <vector>
#include "CommandToken.h"
#include "ConnectorToken.h"


class UserInput{

	public:
		std::string input;
		//vector<UserInput*> 

		void printCommand(){
			std::cout<< "$ ";
		}

		std::string readInput(){ //reading in the user command line
			//wont work for special case "#" - when its in quotes
		
			std::string commandline;
			std::getline(std::cin, commandline);
			
			bool amIquote = false;
			for(int i=0; i<commandline.size();i++){
				if(commandline.at(i) == '\"') {
					amIquote = !amIquote;
				}

				if(commandline.at(i) == '#' && !amIquote){
					commandline = commandline.substr(0, i-1);
				}
			}
			input = commandline + "\0" ; // space indicates when to stop for parsing
			return input;
		}

};
#endif
