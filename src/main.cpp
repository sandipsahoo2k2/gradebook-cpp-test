#include "AllocationManager.hpp"
#include "StudentManager.hpp"
#include "StudentTestsManager.hpp"
#include "GradeBook.hpp"
using namespace std;

void calculateGrade(GradeBook& gradeBook, std::string& studentName, std::string& teacherName)
{
	double finalGrade = gradeBook.getGrade(studentName, teacherName);
	std::cout << "\n----- Grade for " << studentName << " is " << finalGrade << " -------" << std::endl;
}

int main(int argc, char *argv[])
{
        AllocationManager allocationManager;
	std::string inputString = "Y" ;
	while ("Y" == inputString)
	{ 
		std::cout << "Please enter the allocations informations\n";
		std::cout << "Teacher Name:";
		std::string teacherName;
		std::cin >> teacherName;

		std::cout << "Allocation for assignment:";
		double assignmentAllocation;
		std::cin >> assignmentAllocation;

		std::cout << "Allocation for exam:";
		double examAllocation;
		std::cin >> examAllocation;

		std::cout << "Allocation for extra credit:";
		double optionalAllocation;
		std::cin >> optionalAllocation;

		allocationManager.addAllocation(teacherName, assignmentAllocation, examAllocation, optionalAllocation);
		std::cout << "Do you want to add more [Y|N]? ";
		std::cin >> inputString;
	}

	StudentManager studentManager;
	StudentTestsManager studentTestsManager(studentManager);
	GradeBook gradeBook(allocationManager, studentManager, studentTestsManager);

	std::cout << "Please enter the teacher name for grade calculation:";
        std::string teacherName;
        std::cin >> teacherName;

	inputString = "Y";
	while ("Y" == inputString)
	{
		std::cout << "Please enter the student name to be added: ";
		std::string studentName;
		std::cin >> studentName;
        	studentManager.addStudent(studentName);
		std::cout << "Do you want to continue[Y|N]? ";
		std::cin >> inputString;

		inputString = "Y" ;
		while ("Y" == inputString)
		{
			std::cout << "Please enter the score for Assignment: ";
			double score;
			std::cin >> score;
			studentTestsManager.addTestScore(studentName, E_TEST_ASSIGNMENT, score);
			std::cout << "Do you want to add more [Y|N]? ";
			std::cin >> inputString;
			calculateGrade(gradeBook, studentName, teacherName);
		}

		inputString = "Y" ;
                while ("Y" == inputString)
                {
                        std::cout << "Please enter [1|0] if optional assignement is completed:";
                        int completed;
                        std::cin >> completed;
			if(completed)
			{
				studentTestsManager.addTestScore(studentName, E_TEST_OPTIONAL_ASSIGNMENT);
			}
                        std::cout << "Do you want to add more [Y|N]? ";
                        std::cin >> inputString;
			calculateGrade(gradeBook, studentName, teacherName);
                }

		inputString = "Y" ;
                while ("Y" == inputString)
                {
                        std::cout << "Please enter the score for Exam: ";
                        double score;
                        std::cin >> score;
                        studentTestsManager.addTestScore(studentName, E_TEST_EXAM, score);
                        std::cout << "Do you want to add more [Y|N]? ";
                        std::cin >> inputString;
			calculateGrade(gradeBook, studentName, teacherName);
                }
	}

	return 0;
}