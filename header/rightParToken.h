#ifndef _RIGHTPAROKEN_H_
#define _RIGHTPARTOKEN_H_

#include "Token.h"

class rightParToken : public Token{

    public:
	rightParToken(std::string val) {
		this->str = val;
	}
	std::string stringify() {
		return this->str;
	}

	Token* clone() {

		return new rightParToken(this->str);
	}
};

#endif
