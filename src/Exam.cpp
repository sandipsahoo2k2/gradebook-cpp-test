#include "Exam.hpp"
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

Exam::Exam(double score):AbstractGrade(score)
{
	type = E_EXAM ;
	optional = FALSE ;
}

