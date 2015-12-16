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
		std::string toString() const;

		StudentPtr getStudent(const std::string& name) const;

		void addStudent(const std::string& name) ;

		void removeStudent(const std::string& name);

};

#endif
