#include "ITest.hpp"
#include "StudentManager.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

#ifndef _STUDENT_TESTS_MANAGER_H_
#define _STUDENT_TESTS_MANAGER_H_

class StudentTestsManager
{
	private:
		std::map<std::string, std::vector<ITestPtr> > studentTests;
		ITestPtr createATest(ETestType testType, double score);
		StudentManager &studentManager ;

	public:
		StudentTestsManager(StudentManager &studentManager);
		~StudentTestsManager();

		bool addTestScore(std::string studentName, ETestType testType, double score = 0) ;

		void removeTests(std::string studentName);
		
		std::string toString();
		
		const std::vector<ITestPtr> getTests(std::string studentName) const;

		const std::vector<ITestPtr> getOptionalAssignments(std::string studentName) const;

                const std::vector<ITestPtr> getAssignments(std::string studentName) const;

                const std::vector<ITestPtr> getExams(std::string studentName) const;
		
		void printTests(std::string studentName) const;

};

#endif
