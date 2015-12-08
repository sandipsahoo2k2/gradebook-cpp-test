#include "StudentManager.hpp"

const std::vector<StudentPtr>& StudentManager::getStudents() const
{
	return students;
}

StudentPtr StudentManager::getStudent(std::string name) const
{
	StudentPtr student;
	std::vector<StudentPtr>::const_iterator itr  = std::find(students.begin(), students.end(), name);
	if(itr != students.end())
	{
		student = *itr;
	}
	return student;
}

void StudentManager::addStudent(std::string name)
{
	StudentPtr student(new Student(name));
	students.push_back(student);	
}

void StudentManager::removeStudent(std::string name)
{
	StudentPtr student;
	std::vector<StudentPtr>::const_iterator itr  = std::find(students.begin(), students.end(), name);
        if(itr != students.end())
	{
		students.erase(itr);
	}
}

