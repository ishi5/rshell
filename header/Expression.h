#ifndef _EXPRESSION_H
#define _EXPRESSION_H
#include "../header/Token.h"
#include <vector>
#include <string>
#include<iostream>
class Expression{

				public:
						Expression(){};
					//	Expression(Expression* left, Expression* right){
			
						virtual std::string stringify()=0;
						virtual bool evaluate()=0;
						Expression* exp;

				};

#endif
