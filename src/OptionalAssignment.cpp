#include "OptionalAssignment.hpp"
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

OptionalAssignment::OptionalAssignment(double score):AbstractGrade(score)
{
	type = E_OPTIONAL_ASSIGNMENT ;
	optional = TRUE ;
}

