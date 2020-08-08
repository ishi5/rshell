#ifndef _ANDTOKEN_H_
#define _ANDTOKEN_H_

#include "Token.h"

class AndToken : public Token{

    public:
	AndToken(std::string val) {
		this->str = val;
	}
	std::string stringify() {
		return this->str;
	}

	Token* clone() {

		return new AndToken(this->str);
	}
};

#endif
