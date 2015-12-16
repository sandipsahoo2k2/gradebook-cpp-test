#include "Types.hpp"
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

#ifndef _INTERFACE_GRADE_H_
#define _INTERFACE_GRADE_H_

class IGrade
{
	public :
		virtual int getId() const = 0;
		virtual void setId(int id) = 0;
		virtual EGradeType getType() const = 0;
		virtual int isOptional() const = 0;
		virtual double getScore() const = 0;
};

#endif
