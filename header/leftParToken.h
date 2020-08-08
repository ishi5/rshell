#ifndef _LEFTPAROKEN_H_
#define _LEFTPARTOKEN_H_

#include "Token.h"

class leftParToken : public Token{

    public:
	leftParToken(std::string val) {
		this->str = val;
	}
	std::string stringify() {
		return this->str;
	}

	Token* clone() {

		return new leftParToken(this->str);
	}
};

#endif
