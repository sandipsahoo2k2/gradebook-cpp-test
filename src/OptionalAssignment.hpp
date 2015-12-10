#include "AbstractGrade.hpp"
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

#ifndef _OPTIONAL_ASSIGNMENT_H_
#define _OPTIONAL_ASSIGNMENT_H_

class OptionalAssignment : public AbstractGrade
{
public :
	OptionalAssignment(double score);
	virtual ~OptionalAssignment(){} ;

	friend ostream &operator<< (ostream &output, const OptionalAssignment &optionalAssignment)
	{
		output << "\nOptionalAssignment #: " << optionalAssignment.id ;
		output << ", Score: " << optionalAssignment.score ;
	        return output;
	}
};

#endif
