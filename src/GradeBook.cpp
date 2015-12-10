#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <math.h>
#include "GradeBook.hpp"
using namespace std;

GradeBook::GradeBook(AllocationManager &allocationManager, StudentManager &studentManager, StudentGradesManager &studentGradesManager)
		:studentManager(studentManager), studentGradesManager(studentGradesManager), allocationManager(allocationManager)
{
}

GradeBook::~GradeBook()
{
}

bool GradeBook::hasValidGrade(const std::string& forStudentName, const std::string& byTeacherName) const
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
		const std::vector<IGradePtr> exams = studentGradesManager.getExams(forStudentName);
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

bool GradeBook::ignoreAllocation(const std::string& forStudentName) const
{
	bool ignoreAllocation = true;
	StudentPtr student = studentManager.getStudent(forStudentName);
	if(student)
	 {
		const std::vector<IGradePtr> exams = studentGradesManager.getExams(forStudentName);
		if(exams.size() > 0)
		{
			ignoreAllocation = false;
		}
	}
	return ignoreAllocation;
}

double GradeBook::getGrade(const std::string& forStudentName, const std::string& byTeacherName) const
{
	double totalGrade = 0;
	double totalGradeWithoutExam = 0;
	StudentPtr student = studentManager.getStudent(forStudentName);
	if(student)
	{

		const std::vector<IGradePtr> assignments = studentGradesManager.getAssignments(forStudentName);
		double totalAssignmentAverage = calculateAverage(assignments);

		const std::vector<IGradePtr> optionalAssignments = studentGradesManager.getOptionalAssignments(forStudentName);
		double totalOptionalAssignment = optionalAssignments.size();

		totalGradeWithoutExam = totalAssignmentAverage;
		AllocationPtr allocation = allocationManager.getAllocation(byTeacherName);
		if(allocation)
		{
			totalGradeWithoutExam = totalAssignmentAverage + allocation->getOptionalAssignmentAllocation() * totalOptionalAssignment;
		}
		totalGrade = totalGradeWithoutExam;

		const std::vector<IGradePtr> exams = studentGradesManager.getExams(forStudentName);
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

double GradeBook::calculateAverage(const std::vector<IGradePtr>& grades) const
{
	double total = 0;
	double average = 0;

	for(std::vector<IGradePtr>::const_iterator itr = grades.begin(); itr != grades.end(); ++itr)
	{
		total += (*itr)->getScore();
	}
	if(grades.size() > 0)
	{
		average = total / grades.size();
	}
	return average;
}

double GradeBook::calculateTotal(const std::vector<IGradePtr>& grades) const
{
        double total = 0;
        for(std::vector<IGradePtr>::const_iterator itr = grades.begin(); itr != grades.end(); ++itr)
        {
                total += (*itr)->getScore();
        }
        return total;
}
