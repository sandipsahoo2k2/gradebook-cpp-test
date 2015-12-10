#include "StudentGradesManager.hpp"
#include "Exam.hpp"
#include "Assignment.hpp"
#include "OptionalAssignment.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

StudentGradesManager::StudentGradesManager(StudentManager &studentManager):studentManager(studentManager)
{
}

StudentGradesManager::~StudentGradesManager()
{
}

IGradePtr StudentGradesManager::create(EGradeType gradeType, double score)
{
	if(score >= 0 && score <= 100)
	{
		if(gradeType == E_EXAM)
		{
			ExamPtr exam(new Exam(score));
			return exam;
		}
		else if(gradeType == E_ASSIGNMENT)
		{
			AssignmentPtr assignment(new Assignment(score));
			return assignment;
		}
		else if(gradeType == E_OPTIONAL_ASSIGNMENT)
		{
			OptionalAssignmentPtr optionalAssignment(new OptionalAssignment(score));
			return optionalAssignment;
		}
	}
	else
	{
		std::cout << "Invalid Score !!" << std::endl;
	}
	return NULL;
}

bool StudentGradesManager::addGradeScore(const std::string& studentName, EGradeType gradeType, double score)
{
	bool success = false;
	StudentPtr student =  studentManager.getStudent(studentName);
	if(student)
	{
		IGradePtr test = create(gradeType, score);

		std::map<std::string, std::vector<IGradePtr> >::iterator itr = studentGrades.find(studentName);
		if(itr == studentGrades.end())
		{
			test->setId(1);
			std::vector<IGradePtr> tests ;
			tests.push_back(test);
			studentGrades[studentName] = tests; 
		}
		else
		{
			test->setId(studentGrades[studentName].size());
			studentGrades[studentName].push_back(test); 
		}
		success = true;
	}
	else
	{
		std::cout << "Student not found !" <<std::endl ;
	}
	return success;
}

void StudentGradesManager::removeGrades(const std::string& studentName)
{
	studentGrades.erase(studentName);
}

const std::string StudentGradesManager::toString() const
{
	std::ostringstream ss;
	for(std::map<std::string, std::vector<IGradePtr> >::const_iterator itr = studentGrades.begin(); itr != studentGrades.end(); ++itr)
        {
                std::string studentName = itr->first;
		ss << "\nName: " << studentName << std::endl;
		const std::vector<IGradePtr> allGrades = itr->second;
		for(std::vector<IGradePtr>::const_iterator itr = allGrades.begin(); itr != allGrades.end(); ++itr)
		{
			IGradePtr grade = *itr;
			ss << "\nScore: " << grade->getScore() ; 
		}
        }
        return std::string(ss.str());
}
		
const std::vector<IGradePtr> StudentGradesManager::getGrades(const std::string& studentName) const
{
	std::vector<IGradePtr> grades ;
	std::map<std::string, std::vector<IGradePtr> >::const_iterator itr = studentGrades.find(studentName);
        if(itr != studentGrades.end())
        {
		grades = itr->second;
	}
	return grades;
}

const std::vector<IGradePtr> StudentGradesManager::getExams(const std::string& studentName) const
{
	std::vector<IGradePtr> grades = getGrades(studentName);
	std::vector<IGradePtr> exams ;
	for(std::vector<IGradePtr>::const_iterator itr = grades.begin(); itr != grades.end(); ++itr)
        {
                IGradePtr grade = *itr;
                EGradeType gradeType = grade->getType() ;
                if(E_EXAM == gradeType)
                {
			exams.push_back(grade);
                }
        }
	return exams;
}

const std::vector<IGradePtr> StudentGradesManager::getAssignments(const std::string& studentName) const
{
	std::vector<IGradePtr> grades = getGrades(studentName);
        std::vector<IGradePtr> assignments ;
        for(std::vector<IGradePtr>::const_iterator itr = grades.begin(); itr != grades.end(); ++itr)
        {
                IGradePtr grade = *itr;
                EGradeType gradeType = grade->getType() ;
                if(E_ASSIGNMENT == gradeType)
                {
                        assignments.push_back(grade);
                }
        }
        return assignments;
}

const std::vector<IGradePtr> StudentGradesManager::getOptionalAssignments(const std::string& studentName) const
{
	std::vector<IGradePtr> grades = getGrades(studentName);
        std::vector<IGradePtr> optionalAssigments ;
        for(std::vector<IGradePtr>::const_iterator itr = grades.begin(); itr != grades.end(); ++itr)
        {
                IGradePtr grade = *itr;
                EGradeType gradeType = grade->getType() ;
                if(E_OPTIONAL_ASSIGNMENT == gradeType)
                {
                        optionalAssigments.push_back(grade);
                }
        }
        return optionalAssigments;
}
		
void StudentGradesManager::printGrades(const std::string& studentName) const
{
	const std::vector<IGradePtr> grades = getGrades(studentName);
	for(std::vector<IGradePtr>::const_iterator itr = grades.begin(); itr != grades.end(); ++itr)
	{
		std::cout << (*itr);
	}
}
