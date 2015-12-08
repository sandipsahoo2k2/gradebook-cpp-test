#include "StudentTestsManager.hpp"
#include "Exam.hpp"
#include "Assignment.hpp"
#include "OptionalAssignment.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

StudentTestsManager::StudentTestsManager(StudentManager &studentManager):studentManager(studentManager)
{
}

StudentTestsManager::~StudentTestsManager()
{
}

ITestPtr StudentTestsManager::createATest(ETestType testType, double score)
{
	if(score >= 0 && score <= 100)
	{
		if(testType == E_TEST_EXAM)
		{
			ExamPtr exam(new Exam(score));
			return exam;
		}
		else if(testType == E_TEST_ASSIGNMENT)
		{
			AssignmentPtr assignment(new Assignment(score));
			return assignment;
		}
		else if(testType == E_TEST_OPTIONAL_ASSIGNMENT)
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

bool StudentTestsManager::addTestScore(std::string studentName, ETestType testType, double score)
{
	bool success = false;
	StudentPtr student =  studentManager.getStudent(studentName);
	if(student)
	{
		ITestPtr test = createATest(testType, score);

		std::map<std::string, std::vector<ITestPtr> >::iterator itr = studentTests.find(studentName);
		if(itr == studentTests.end())
		{
			test->setId(1);
			std::vector<ITestPtr> tests ;
			tests.push_back(test);
			studentTests[studentName] = tests; 
		}
		else
		{
			test->setId(studentTests[studentName].size());
			studentTests[studentName].push_back(test); 
		}
		success = true;
	}
	else
	{
		std::cout << "Student not found !" <<std::endl ;
	}
	return success;
}

void StudentTestsManager::removeTests(std::string studentName)
{
	studentTests.erase(studentName);
}

std::string StudentTestsManager::toString()
{
	for(std::map<std::string, std::vector<ITestPtr> >::iterator itr = studentTests.begin(); itr != studentTests.end(); ++itr)
        {
                std::string studentName = itr->first;
		std::cout << "\nName: " << studentName << std::endl;
		const std::vector<ITestPtr> allTests = itr->second;
		for(std::vector<ITestPtr>::const_iterator itr = allTests.begin(); itr != allTests.end(); ++itr)
		{
			ITestPtr singleTest = *itr;
			std::cout << "\nScore: " << singleTest->getScore() ; 
		}
        }
	return "";
}
		
const std::vector<ITestPtr> StudentTestsManager::getTests(std::string studentName) const
{
	std::vector<ITestPtr> tests ;
	std::map<std::string, std::vector<ITestPtr> >::const_iterator itr = studentTests.find(studentName);
        if(itr != studentTests.end())
        {
		tests = itr->second;
	}
	return tests;
}

const std::vector<ITestPtr> StudentTestsManager::getExams(std::string studentName) const
{
	std::vector<ITestPtr> allTests = getTests(studentName);
	std::vector<ITestPtr> exams ;
	for(std::vector<ITestPtr>::const_iterator itr = allTests.begin(); itr != allTests.end(); ++itr)
        {
                ITestPtr singleTest = *itr;
                ETestType testType = singleTest->getType() ;
                if(E_TEST_EXAM == testType)
                {
			exams.push_back(singleTest);
                }
        }
	return exams;
}

const std::vector<ITestPtr> StudentTestsManager::getAssignments(std::string studentName) const
{
	std::vector<ITestPtr> allTests = getTests(studentName);
        std::vector<ITestPtr> assignments ;
        for(std::vector<ITestPtr>::const_iterator itr = allTests.begin(); itr != allTests.end(); ++itr)
        {
                ITestPtr singleTest = *itr;
                ETestType testType = singleTest->getType() ;
                if(E_TEST_ASSIGNMENT == testType)
                {
                        assignments.push_back(singleTest);
                }
        }
        return assignments;
}

const std::vector<ITestPtr> StudentTestsManager::getOptionalAssignments(std::string studentName) const
{
	std::vector<ITestPtr> allTests = getTests(studentName);
        std::vector<ITestPtr> optionalAssigments ;
        for(std::vector<ITestPtr>::const_iterator itr = allTests.begin(); itr != allTests.end(); ++itr)
        {
                ITestPtr singleTest = *itr;
                ETestType testType = singleTest->getType() ;
                if(E_TEST_OPTIONAL_ASSIGNMENT == testType)
                {
                        optionalAssigments.push_back(singleTest);
                }
        }
        return optionalAssigments;
}
		
void StudentTestsManager::printTests(std::string studentName) const
{
	const std::vector<ITestPtr> allTests = getTests(studentName);
	for(std::vector<ITestPtr>::const_iterator itr = allTests.begin(); itr != allTests.end(); ++itr)
	{
		std::cout << (*itr);
	}
}
