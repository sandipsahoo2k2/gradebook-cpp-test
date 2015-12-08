#include "ITest.hpp"
#include "Student.hpp"
#include "StudentManager.hpp"
#include "StudentTestsManager.hpp"
#include "AllocationManager.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

#ifndef _GRADE_BOOK_H_
#define _GRADE_BOOK_H_

class GradeBook
{
	private:
		StudentManager &studentManager ;
		StudentTestsManager &studentTestsManager;
		AllocationManager &allocationManager;
		
		/* An optimised version */
		bool calculateGrade(const std::vector<ITestPtr>& allTests, AllocationPtr allocation) const;
		
		double calculateTotal(const std::vector<ITestPtr>& tests) const;

		double calculateAverage(const std::vector<ITestPtr>& tests) const;

	public:
		GradeBook(AllocationManager &allocationManager, StudentManager &studentManager, StudentTestsManager &studentTestsManager);

		~GradeBook();

		bool hasValidGrade(std::string forStudentName, std::string byTeacherName) const;

		bool ignoreAllocation(std::string forStudentName) const;

		double getGrade(std::string forStudentName, std::string byTeacherName) const;
};

#endif

