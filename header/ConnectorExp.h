#ifndef _CONNECTOREXP_H_
#define _CONNECTOREXP_H_

//#include "../header/Token.h"
#include "../header/Expression.h"
#include <vector>
#include <string>
#include<iostream>


class ConnectorExp: public Expression{
			
	public:
			
		virtual std::string stringify()=0;
		virtual bool evaluate()=0;
				

};

#endif
