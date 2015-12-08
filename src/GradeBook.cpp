#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <math.h>
#include "GradeBook.hpp"
using namespace std;

GradeBook::GradeBook(AllocationManager &allocationManager, StudentManager &studentManager, StudentTestsManager &studentTestsManager)
		:studentManager(studentManager), studentTestsManager(studentTestsManager), allocationManager(allocationManager)
{
}

GradeBook::~GradeBook()
{
}

bool GradeBook::hasValidGrade(std::string forStudentName, std::string byTeacherName) const
{
        bool canCalculateGrade = false;
	AllocationPtr allocation = allocationManager.getAllocation(byTeacherName);
	if(allocation)
	{
		canCalculateGrade = true;
	}

        StudentPtr student = studentManager.getStudent(forStudentName);
        if(student)
        {
		const std::vector<ITestPtr> exams = studentTestsManager.getExams(forStudentName);
                if(exams.size() > 0)
		{
			if(!allocation)
			{
				canCalculateGrade = false;
			}
			else
			{
				canCalculateGrade = true;
			}
		}
		else
		{
			canCalculateGrade = true;
		}
        }
	else
	{
		canCalculateGrade = false;
	}
        return canCalculateGrade;
}

bool GradeBook::ignoreAllocation(std::string forStudentName) const
{
	bool ignoreAllocation = true;
	StudentPtr student = studentManager.getStudent(forStudentName);
	if(student)
	 {
		const std::vector<ITestPtr> exams = studentTestsManager.getExams(forStudentName);
		if(exams.size() > 0)
		{
			ignoreAllocation = false;
		}
	}
	return ignoreAllocation;
}

double GradeBook::getGrade(std::string forStudentName, std::string byTeacherName) const
{
	double totalGrade = 0;
	double totalGradeWithoutExam = 0;
	StudentPtr student = studentManager.getStudent(forStudentName);
	if(student)
	{

		const std::vector<ITestPtr> assignments = studentTestsManager.getAssignments(forStudentName);
		double totalAssignmentAverage = calculateAverage(assignments);

		const std::vector<ITestPtr> optionalAssignments = studentTestsManager.getOptionalAssignments(forStudentName);
		double totalOptionalAssignment = optionalAssignments.size();

		totalGradeWithoutExam = totalAssignmentAverage;
		AllocationPtr allocation = allocationManager.getAllocation(byTeacherName);
		if(allocation)
		{
			totalGradeWithoutExam = totalAssignmentAverage + allocation->getOptionalAssignmentAllocation() * totalOptionalAssignment;
		}
		totalGrade = totalGradeWithoutExam;

		const std::vector<ITestPtr> exams = studentTestsManager.getExams(forStudentName);
		if(exams.size() > 0)
		{
			double totalExamAverage = calculateAverage(exams);
			if(allocation)
			{
				totalGrade = (allocation->getExamAllocation() * totalExamAverage + allocation->getAssignmentAllocation() * totalGradeWithoutExam) / 100 ;
			}
			else
			{
				totalGrade = 0;
				std::cout << "Error !! Allocation not found for: " << byTeacherName << std::endl;
			}
		}
	}
	else
	{
		std::cout << "Student name not found !" << std::endl;
	}

	totalGrade = floorf(totalGrade * 100) / 100;
	return totalGrade;
}

/* if we want to save memory and optimise the code use this function instead */
bool GradeBook::calculateGrade(const std::vector<ITestPtr>& allTests, AllocationPtr allocation) const
{
        double totalGrade = 0 ;

	double totalGradeForExam = 0;
	double totalGradeForAssignment = 0;
	double totalGradeForOptionalAssignment = 0;
		
	int examCounter = 0;
	int assignmentCounter = 0;
	int optionalAssignmentCounter = 0;

        for(std::vector<ITestPtr>::const_iterator itr = allTests.begin(); itr != allTests.end(); ++itr)
        {
		ITestPtr singleTest = *itr;
		ETestType testType = singleTest->getType() ;
                if(E_TEST_EXAM == testType)
                {
			examCounter ++;
			totalGradeForExam += singleTest->getScore();
                }
		else if(E_TEST_ASSIGNMENT == testType)
		{
			assignmentCounter++;
			totalGradeForAssignment += singleTest->getScore();
		}
		else if(E_TEST_OPTIONAL_ASSIGNMENT == testType)
		{
			optionalAssignmentCounter++;
			totalGradeForOptionalAssignment += singleTest->getScore();
		}
        }
	if(examCounter > 0)
	{
		double totalAverageAssignmentGrade = 0;
		double totalAverageExamGrade = allocation->getExamAllocation() * (totalGradeForExam / examCounter) ;
		if(assignmentCounter > 0)
		{
			totalAverageAssignmentGrade = allocation->getAssignmentAllocation() * (totalGradeForAssignment / assignmentCounter) ;
		}
		double totalOptionalAssignmentGrade = allocation->getOptionalAssignmentAllocation() * optionalAssignmentCounter ;
		totalGrade = totalAverageExamGrade + totalAverageAssignmentGrade + totalOptionalAssignmentGrade;
	}
        return totalGrade;
}

double GradeBook::calculateAverage(const std::vector<ITestPtr>& tests) const
{
	double total = 0;
	double average = 0;

	for(std::vector<ITestPtr>::const_iterator itr = tests.begin(); itr != tests.end(); ++itr)
	{
		total += (*itr)->getScore();
	}
	if(tests.size() > 0)
	{
		average = total / tests.size();
	}
	return average;
}

double GradeBook::calculateTotal(const std::vector<ITestPtr>& tests) const
{
        double total = 0;
        for(std::vector<ITestPtr>::const_iterator itr = tests.begin(); itr != tests.end(); ++itr)
        {
                total += (*itr)->getScore();
        }
        return total;
}
