#ifndef _SEMITOKEN_H_
#define _SEMITOKEN_H_

#include "Token.h"

class SemiToken : public Token{

    public:
	SemiToken(std::string val) {
		this->str = val;
	}
	std::string stringify() {
		return this->str;
	}

	Token* clone() {

		return new SemiToken(this->str);
	}
};

#endif
