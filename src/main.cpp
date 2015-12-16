#include "AllocationManager.hpp"
#include "StudentManager.hpp"
#include "StudentGradesManager.hpp"
#include "GradeBook.hpp"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

void calculateGrade(GradeBook& gradeBook, std::string& studentName, std::string& teacherName)
{
	double finalGrade = gradeBook.getFinalGradeForStudentByTeacher(studentName, teacherName);
	std::cout << "\n----- Grade for " << studentName << " is " << finalGrade << " -------" << std::endl;
}

char selectMainMenu()
{
	std::cin.clear();	
	char mainMenuOption ;
	string usrstr;
	std::cout << "\nMAIN MENU:\n";
	std::cout << "Select A: To create student db"<<std::endl;
	std::cout << "Select B: To create allocation db"<<std::endl;
	std::cout << "Select C: To calculate grade for student by teacher"<<std::endl;
	std::cout << "Select D: To print student db"<<std::endl;
	std::cout << "Select E: To print allocation db"<<std::endl;
	std::cout << "Select Z: To terminate the program"<<std::endl;
	std::cout << "Select: " ;
	getline (cin,usrstr);
	stringstream(usrstr) >> mainMenuOption;
	std::cout << std::endl ;
	return mainMenuOption;
}

int selectSubMenu()
{
	std::cin.clear();	
	string usrstr;
	int submenuOption ;
	std::cout << "\nSUB MENU:\n";
	std::cout << "Select 1: To input score for Assignment" << std::endl;
	std::cout << "Select 2: To input score for Exam" << std::endl;
	std::cout << "Select 3: To input if Optiona/Extra Credit assignment is completed or not" << std::endl;
	std::cout << "Select 0: To go to main menu" << std::endl;
	std::cout << "Select :" ;
	getline (cin,usrstr);
	stringstream(usrstr) >> submenuOption;
	std::cout << std::endl ;
	return submenuOption;
}

int main(int argc, char *argv[])
{
	AllocationManager allocationManager;
	StudentManager studentManager;
	StudentGradesManager studentGradesManager(studentManager);
	GradeBook gradeBook(allocationManager, studentManager, studentGradesManager);

	char mainMenuOption = selectMainMenu();
	while(mainMenuOption != 'Z' && mainMenuOption != 'z')
	{
		switch(mainMenuOption)
		{
			case 'A':
			case 'a':
				{
					std::cout << "Please enter the student name to be added: ";
					std::string studentName;
					getline(std::cin,studentName);
					studentManager.addStudent(studentName);
				}
				break;
			case 'B':
			case 'b':
				{
					std::cout << "Please enter the allocations informations\n";
					std::cout << "Teacher Name:";
					std::string teacherName;
					getline(std::cin,teacherName);
					std::cin.clear();

					string usrstr("");
					std::cout << "Allocation for assignment in (%):";
					double assignmentAllocation;
					getline (cin,usrstr);
					stringstream(usrstr) >> assignmentAllocation;

					std::cout << "Allocation for exam in (%):";
					double examAllocation;
					getline (cin,usrstr);
					stringstream(usrstr) >> examAllocation;

					std::cout << "Allocation for extra credit in (%):";
					double optionalAllocation;
					getline (cin,usrstr);
					stringstream(usrstr) >> optionalAllocation;

					allocationManager.addAllocation(teacherName, assignmentAllocation, examAllocation, optionalAllocation);
				}
				break;
			case 'C':
			case 'c':
				{
					std::cout << "\nCALCULATE GRADE FOR STUDENT BY TEACHER\n";
					std::cout << "Note : Without the teacher and student name provided grade can not be calculated on the fly!" <<std::endl;
					std::cout << "Please enter the teacher name:";
					std::string teacherName;
					getline(std::cin,teacherName);
					AllocationPtr allocation = allocationManager.getAllocation(teacherName);
					if(!allocation)
					{
						std::cout << "Allocation information not found for: " << teacherName << std::endl;
						break;
					}

					std::cout << "Please enter the student name:";
					std::string studentName;
					getline(std::cin,studentName);
					StudentPtr student = studentManager.getStudent(studentName);
					if(!student)
					{
						std::cout << "Student information not found for: " << studentName << std::endl;
						break;
					}
					int option = selectSubMenu();
					while (option != 0)
					{
						if(option == 1)
						{
							std::string usrstr;
							std::cout << "Please enter the score for Assignment: ";
							double score;
							getline (cin,usrstr);
							stringstream(usrstr) >> score;
							studentGradesManager.addStudentsGradeScore(studentName, E_ASSIGNMENT, score);
							calculateGrade(gradeBook, studentName, teacherName);
						}
						else if(option == 2)
						{
							std::string usrstr;
							std::cout << "Please enter the score for Exam: ";
							double score;
							getline (cin,usrstr);
							stringstream(usrstr) >> score;
							studentGradesManager.addStudentsGradeScore(studentName, E_EXAM, score);
							calculateGrade(gradeBook, studentName, teacherName);
						}
						else if(option == 3)
						{
							std::cout << "Please enter [Y|N] if optional assignment is completed:";
							std::string completed;
							getline(std::cin,completed);
							if(completed == "Y" || completed == "y")
							{
								studentGradesManager.addStudentsGradeScore(studentName, E_OPTIONAL_ASSIGNMENT);
							}
							calculateGrade(gradeBook, studentName, teacherName);
						}
						option = selectSubMenu();
					}
				}
				break;
			case 'D':
			case 'd':
				{
					std::cout << studentManager.toString();
				}
				break;
			case 'E':
			case 'e':
				{
					std::cout << allocationManager.toString();
				}
				break;
			case 'Z':
			case 'z':
			default:
				break;
		}
		mainMenuOption = selectMainMenu();
	}

	std::cout << "\nAPPLICATION GRADEBOOK STOPS\n";
	return 0;
}
