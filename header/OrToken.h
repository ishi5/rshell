#ifndef _OR_H_
#define _OR_H_

#include "Token.h"

class OrToken: public Token{

	public:
	OrToken	(std::string val) {
		this->str = val;
	}
		
	std::string stringify() {
		return this->str;
	}

	Token* clone() {

		return new OrToken(this->str);
	}
};

#endif
