#ifndef _ARG_H_
#define _ARG_H_

#include "Token.h"

class ArgToken : public Token{

	public:
	ArgToken(std::string val) {
		this->str = val;
	}
		
	std::string stringify() {
		return this->str;
	}
};

#endif
