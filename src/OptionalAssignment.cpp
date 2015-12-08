#include "OptionalAssignment.hpp"
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

OptionalAssignment::OptionalAssignment(double score):AbstractTest(score)
{
	type = E_TEST_OPTIONAL_ASSIGNMENT ;
	optional = TRUE ;
}

