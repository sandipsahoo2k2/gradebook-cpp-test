#include "Types.hpp"
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

#ifndef _ALLOCATION_H_
#define _ALLOCATION_H_

class Allocation
{
	private :
		double assignmentAllocation;
		double examAllocation;
		double optionalAssignmentAllocation; 
	public :
		Allocation(double assignmentAllocation, double examAllocation, double optionalAssignmentAllocation);
		~Allocation() {};

		double getAssignmentAllocation() const;

		double getExamAllocation() const;

		double getOptionalAssignmentAllocation() const;

		friend ostream &operator<< (ostream &output, const Allocation &allocation)
		{
			output << "\nAssignment: " << allocation.assignmentAllocation ;
			output << "\nExam: " << allocation.examAllocation ;
			output << "\nExtraCredit: " << allocation.optionalAssignmentAllocation ;
			return output;
		}
};

#endif
