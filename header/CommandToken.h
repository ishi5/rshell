#ifndef _COMMAND_H_
#define _COMMAND_H_

#include "Token.h"

class CommandToken : public Token{

	public:
	CommandToken(std::string val) {
		this->str = val;
	}
		
	std::string stringify() {
		return this->str;
	}

	Token* clone() {

		return new CommandToken(this->str);
	}
};

#endif


