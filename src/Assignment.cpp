#include "Assignment.hpp"
#include "AbstractTest.hpp"
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

Assignment::Assignment(double score):AbstractTest(score)
{
	type = E_TEST_ASSIGNMENT ;
	optional = FALSE ;
}
