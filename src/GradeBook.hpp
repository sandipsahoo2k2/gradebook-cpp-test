#include "Student.hpp"
#include "StudentManager.hpp"
#include "StudentGradesManager.hpp"
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
		StudentGradesManager &studentGradesManager;
		AllocationManager &allocationManager;
		
		double calculateTotal(const std::vector<IGradePtr>& grades) const;

		double calculateAverage(const std::vector<IGradePtr>& grades) const;

	public:
		GradeBook(AllocationManager &allocationManager, StudentManager &studentManager, StudentGradesManager &studentGradesManager);

		~GradeBook();

		bool hasValidGrade(const std::string& forStudentName, const std::string& byTeacherName) const;

		bool ignoreAllocation(const std::string& forStudentName) const;

		double getGrade(const std::string& forStudentName, const std::string& byTeacherName) const;
};

#endif

