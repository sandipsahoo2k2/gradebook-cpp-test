#include "Types.hpp"
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

#ifndef _INTERFACE_TEST_H_
#define _INTERFACE_TEST_H_

class ITest
{
public :
	virtual int getId() const = 0;
	virtual void setId(int id) = 0;
	virtual ETestType getType() const = 0;
	virtual int isOptional() const = 0;
	virtual double getScore() const = 0;
};

#endif
