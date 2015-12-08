#include "Allocation.hpp"
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

Allocation::Allocation(double assignmentAllocation, double examAllocation, double optionalAssignmentAllocation)
	:assignmentAllocation(assignmentAllocation), examAllocation(examAllocation),optionalAssignmentAllocation(optionalAssignmentAllocation)
{
}

double Allocation::getAssignmentAllocation() const
{
	return assignmentAllocation;
}

double Allocation::getExamAllocation() const
{
	return examAllocation;
}

double Allocation::getOptionalAssignmentAllocation() const
{
	return optionalAssignmentAllocation;
}

