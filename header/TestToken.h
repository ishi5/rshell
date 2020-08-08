#ifndef _TEST_TOKEN_H_
#define _TEST_TOKEN_H_

#include "Token.h"

class TestToken : public Token{

    public:
	TestToken(std::string val) {
		this->str = val;
	}
	std::string stringify() {
		return this->str;
	}

	Token* clone() {

		return new TestToken(this->str);
	}
};

#endif
