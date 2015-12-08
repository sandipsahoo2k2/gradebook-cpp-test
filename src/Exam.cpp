#include "Exam.hpp"
#include "AbstractTest.hpp"
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

Exam::Exam(double score):AbstractTest(score)
{
	type = E_TEST_EXAM ;
	optional = FALSE ;
}

