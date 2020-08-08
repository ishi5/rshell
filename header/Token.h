#ifndef _TOKEN_H_
#define _TOKEN_H_

#include <string>
#include <iostream>


class Token{

	public:	
         	std::string str;
		Token() {};
		Token(std::string temp) {
			str = temp;
		}
		void setVal(std::string val) {
			str = val;
		}
		virtual std::string stringify() = 0;
		
		virtual Token* clone() = 0;
};

#endif
