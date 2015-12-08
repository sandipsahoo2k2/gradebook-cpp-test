#include "Student.hpp"

Student::Student(std::string name):name(name)
{
}

const std::string& Student::getName() const
{
	return name;
}

