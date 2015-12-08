#include "ITest.hpp"
#include "Types.hpp"
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

#ifndef _ABSTRACT_TEST_H_
#define _ABSTRACT_TEST_H_

class AbstractTest : public ITest
{
protected :
	int id;
	double score;
	ETestType type; 
	int optional;
public :
	AbstractTest(double score);

	virtual ~AbstractTest() = 0;

	virtual ETestType getType() const;

	virtual void setId(int id);

	virtual int getId() const;

	virtual double getScore() const;
	
	virtual int isOptional() const;
};

#endif
