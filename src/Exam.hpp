#include "AbstractGrade.hpp"
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

#ifndef _EXAM_H_
#define _EXAM_H_

class Exam : public AbstractGrade
{
	public :
		Exam(double score);
		virtual ~Exam(){};

		friend ostream &operator<< (ostream &output, const Exam &exam)
		{
			output << "\nExam #: " << exam.id ;
			output << ", Score: " << exam.score ;
			return output;
		}
};

#endif
