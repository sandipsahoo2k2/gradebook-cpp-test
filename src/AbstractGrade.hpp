#include "IGrade.hpp"
#include "Types.hpp"
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

#ifndef _ABSTRACT_GRADE_H_
#define _ABSTRACT_GRADE_H_

class AbstractGrade : public IGrade
{
protected :
	int id;
	double score;
	EGradeType type; 
	int optional;
public :
	AbstractGrade(double score);

	virtual ~AbstractGrade() = 0;

	virtual EGradeType getType() const;

	virtual void setId(int id);

	virtual int getId() const;

	virtual double getScore() const;
	
	virtual int isOptional() const;
};

#endif
