#include "Types.hpp"
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

#ifndef _STUDENT_H_
#define _STUDENT_H_

class Student
{
private :
	std::string name;
public :
	Student(std::string name);
	~Student() {};

	const std::string& getName() const ;

	friend bool operator==(StudentPtr student, const std::string& name)
	{
		bool match = false;
		if(student->getName() == name)
		{
			match = true;
		}
		return match;
	}

	friend ostream &operator<< (ostream &output, const Student &student)
	{
		output << "\nName: " << student.name ;
	        return output;
	}
};


#endif
