#include "AbstractGrade.hpp"
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

#ifndef _ASSIGNMENT_H_
#define _ASSIGNMENT_H_

class Assignment : public AbstractGrade
{
	public :
		Assignment(double score);
		~Assignment(){};

		friend ostream &operator<< (ostream &output, const Assignment &assignment)
		{
			output << "\nAssignment #: " << assignment.id ;
			output << ", Score: " << assignment.score ;
			return output;
		}
};

#endif
