#ifndef _TYPES_H
#define _TYPES_H

#include <string>
class Student;
class Allocation;
class ITest;
class Exam;
class Assignment;
class OptionalAssignment;

enum ETestType {
	E_TEST_INVALID = 0,
	E_TEST_EXAM = 1,
	E_TEST_ASSIGNMENT = 2,
	E_TEST_OPTIONAL_ASSIGNMENT = 3
	};

const int TRUE = 1;
const int FALSE = 0;
typedef std::shared_ptr<Student> StudentPtr;
typedef std::shared_ptr<Allocation> AllocationPtr;
typedef std::shared_ptr<ITest> ITestPtr;
typedef std::shared_ptr<Exam> ExamPtr;
typedef std::shared_ptr<Assignment> AssignmentPtr;
typedef std::shared_ptr<OptionalAssignment> OptionalAssignmentPtr;

#endif
