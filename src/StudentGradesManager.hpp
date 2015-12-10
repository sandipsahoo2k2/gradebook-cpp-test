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

		bool addGradeScore(const std::string& studentName, EGradeType gradeType, double score = 0) ;

		void removeGrades(const std::string& studentName);
		
		const std::string toString() const;
		
		const std::vector<IGradePtr> getGrades(const std::string& studentName) const;

		const std::vector<IGradePtr> getOptionalAssignments(const std::string& studentName) const;

                const std::vector<IGradePtr> getAssignments(const std::string& studentName) const;

                const std::vector<IGradePtr> getExams(const std::string& studentName) const;
		
		void printGrades(const std::string& studentName) const;

};

#endif
