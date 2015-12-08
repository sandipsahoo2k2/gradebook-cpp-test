#include "Student.hpp"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#ifndef _STUDENT_MANAGER_H_
#define _STUDENT_MANAGER_H_

class StudentManager
{
	private:
		std::vector<StudentPtr> students;

	public:
		const std::vector<StudentPtr>& getStudents() const;
	
		void addStudent(std::string name) ;

		void removeStudent(std::string name);

		StudentPtr getStudent(std::string name) const;

};

#endif
