#include "StudentManager.hpp"
#include <algorithm>

const std::vector<StudentPtr>& StudentManager::getStudents() const
{
	return students;
}

StudentPtr StudentManager::getStudent(const std::string& name) const
{
	StudentPtr student;
	std::vector<StudentPtr>::const_iterator itr  = std::find(students.begin(), students.end(), name);
	if(itr != students.end())
	{
		student = *itr;
	}
	return student;
}

void StudentManager::addStudent(const std::string& name)
{
	StudentPtr student(new Student(name));
	students.push_back(student);	
}

void StudentManager::removeStudent(const std::string& name)
{
	StudentPtr student;
	std::vector<StudentPtr>::iterator itr  = std::find(students.begin(), students.end(), name);
        if(itr != students.end())
	{
		students.erase(itr);
	}
}

