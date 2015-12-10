#ifndef _TYPES_H
#define _TYPES_H

#include <string>
class Student;
class Allocation;
class IGrade;
class Exam;
class Assignment;
class OptionalAssignment;

enum EGradeType {
	E_INVALID = 0,
	E_EXAM = 1,
	E_ASSIGNMENT = 2,
	E_OPTIONAL_ASSIGNMENT = 3
	};

const int TRUE = 1;
const int FALSE = 0;
typedef std::shared_ptr<Student> StudentPtr;
typedef std::shared_ptr<Allocation> AllocationPtr;
typedef std::shared_ptr<IGrade> IGradePtr;
typedef std::shared_ptr<Exam> ExamPtr;
typedef std::shared_ptr<Assignment> AssignmentPtr;
typedef std::shared_ptr<OptionalAssignment> OptionalAssignmentPtr;

#endif
