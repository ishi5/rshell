#ifndef _EXIT_TOKEN_H_
#define _EXIT_TOKEN_H_

#include "Token.h"

class ExitToken : public Token{

    public:
	ExitToken(std::string val) {
		this->str = val;
	}
	std::string stringify() {
		return this->str;
	}

	Token* clone() {

		return new ExitToken(this->str);
	}
};

#endif

