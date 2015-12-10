#include "Assignment.hpp"
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

Assignment::Assignment(double score):AbstractGrade(score)
{
	type = E_ASSIGNMENT ;
	optional = FALSE ;
}
