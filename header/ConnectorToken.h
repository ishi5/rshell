#ifndef _CONNECTOR_H_
#define _CONNECTOR_H_

#include "Token.h"

class Connector : public Token{

        public:
	Connector(std::string val) {
		this->str = val;
	}
	std::string stringify() {
		return this->str;
	}

	Token* clone() {

		return new Connector(this->str);
	}
};

#endif
