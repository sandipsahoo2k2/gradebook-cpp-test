#include "IGrade.hpp"
#include "StudentManager.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

#ifndef _STUDENT_GRADES_MANAGER_H_
#define _STUDENT_GRADES_MANAGER_H_

class StudentGradesManager
{
	private:
		std::map<std::string, std::vector<IGradePtr> > studentGrades;
		IGradePtr create(EGradeType gradeType, double score);
		StudentManager &studentManager ;

	public:
		StudentGradesManager(StudentManager &studentManager);
		~StudentGradesManager();

		bool addGradeScore(std::string studentName, EGradeType gradeType, double score = 0) ;

		void removeGrades(std::string studentName);
		
		void printString();
		
		const std::vector<IGradePtr> getGrades(std::string studentName) const;

		const std::vector<IGradePtr> getOptionalAssignments(std::string studentName) const;

                const std::vector<IGradePtr> getAssignments(std::string studentName) const;

                const std::vector<IGradePtr> getExams(std::string studentName) const;
		
		void printGrades(std::string studentName) const;

};

#endif
