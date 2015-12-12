#include "AllocationManager.hpp"
#include "StudentManager.hpp"
#include "StudentGradesManager.hpp"
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
	StudentManager studentManager;
	StudentGradesManager studentGradesManager(studentManager);
	GradeBook gradeBook(allocationManager, studentManager, studentGradesManager);

	std::cout << "\nCREATE STUDENT DB\n";

	std::string inputString = "Y" ;
	while ("Y" == inputString || "y" == inputString)
	{
		std::cout << "Please enter the student name to be added: ";
		std::string studentName;
		std::cin >> studentName;
        	studentManager.addStudent(studentName);
		std::cout << "Do you want to continue[Y|N]? ";
		std::cin >> inputString;
	}

	std::cout << "\nCREATE ALLOCATIONS DB\n";
	inputString = "Y" ;
	while ("Y" == inputString || "y" == inputString)
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


	std::cout << "\nCALCULATE GRADE FOR STUDENT BY TEACHER\n";

	std::cout << "Note : Without the teacher and student name provided grade can not be calculated on the fly!" <<std::endl;
	std::cout << "Please enter the teacher name:";
        std::string teacherName;
        std::cin >> teacherName;
	AllocationPtr allocation = allocationManager.getAllocation(teacherName);
	if(!allocation)
	{
		std::cout << "Allocation information not found for: " << teacherName << std::endl;
		std::cout << "\nAPPLICATION GRADEBOOK STOPS\n";
		return -1;
	}

	std::cout << "Please enter the student name:";
        std::string studentName;
        std::cin >> studentName;
	StudentPtr student = studentManager.getStudent(studentName);
	if(!student)
	{
		std::cout << "Student information not found for: " << studentName << std::endl;
		std::cout << "\nAPPLICATION GRADEBOOK STOPS\n";
		return -1;
	}

	inputString = "Y";
	int option = 0 ;
	std::cin.clear();	
	std::cout << "Please choose option Assignment:1, Exam:2 or OptionalAssignment/Extra Credit:3 for entering score" << std::endl;
	std::cout << "Select [1|2|3] or 0 to discontinue:" ;
	std::cin >> option ;
	while (option != 0)
	{
		if(option == 1)
		{
			std::cout << "Please enter the score for Assignment: ";
			double score;
			std::cin >> score;
			studentGradesManager.addGradeScore(studentName, E_ASSIGNMENT, score);
			calculateGrade(gradeBook, studentName, teacherName);
		}
		else if(option == 2)
		{
			std::cout << "Please enter the score for Exam: ";
			double score;
			std::cin >> score;
			studentGradesManager.addGradeScore(studentName, E_EXAM, score);
			calculateGrade(gradeBook, studentName, teacherName);
		}
		else if(option == 3)
		{
			std::cout << "Please enter [1|0] if optional assignement is completed:";
			int completed;
			std::cin >> completed;
			if(completed)
			{
				studentGradesManager.addGradeScore(studentName, E_OPTIONAL_ASSIGNMENT);
			}
			calculateGrade(gradeBook, studentName, teacherName);
		}
		std::cout << "To continue choose option [Assignment:1, Exam:2 or OptionalAssignment:3] or 0 to discontinue:" ;
		std::cin >> option ;
	}
	std::cout << "\nAPPLICATION GRADEBOOK STOPS\n";
	return 0;
}
