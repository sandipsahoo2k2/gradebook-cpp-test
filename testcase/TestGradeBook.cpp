#include "TestGradeBook.hpp"

CppUnit::Test *TestGradeBook::suite()
{
	CppUnit::TestSuite *suiteOfTests = new CppUnit::TestSuite("GradeBook");
	suiteOfTests->addTest(new CppUnit::TestCaller<TestGradeBook>(
				"Check if Grade Available",
				&TestGradeBook::checkGradeAvailable));
	suiteOfTests->addTest(new CppUnit::TestCaller<TestGradeBook>(
				"Calculate a simple Grade",
				&TestGradeBook::calculateSimpleGrade));

	suiteOfTests->addTest(new CppUnit::TestCaller<TestGradeBook>(
				"Calculate Grade with out exam",
				&TestGradeBook::calculateGradeWithoutExam));

	suiteOfTests->addTest(new CppUnit::TestCaller<TestGradeBook>(
				"Calculate Grade with exam",
				&TestGradeBook::calculateGradeWithExam));
	return suiteOfTests;
}

void TestGradeBook::checkGradeAvailable()
{
	StudentManager studentManager;
	studentManager.addStudent("Sally");
	StudentGradesManager studentGradesManager(studentManager);
	studentGradesManager.addStudentsGradeScore("Sally", E_EXAM, 80.1);
	studentGradesManager.addStudentsGradeScore("Sally", E_EXAM, 80.1);

	AllocationManager allocationManager;
	allocationManager.addAllocation("Grahm", 10, 90, 2);

	GradeBook toBeTestedObject(allocationManager, studentManager, studentGradesManager);
	CPPUNIT_ASSERT(toBeTestedObject.checkIfStudentHasValidGrade("Sally", "Grahm") == true);
	CPPUNIT_ASSERT(toBeTestedObject.checkIfStudentHasValidGrade("Sally", "Greg") == false);
}

void TestGradeBook::calculateSimpleGrade()
{
	StudentManager studentManager;
	studentManager.addStudent("Sally");
	StudentGradesManager studentGradesManager(studentManager);
	studentGradesManager.addStudentsGradeScore("Sally", E_EXAM, 100);
	studentGradesManager.addStudentsGradeScore("Sally", E_EXAM, 100);

	AllocationManager allocationManager;
	allocationManager.addAllocation("Grahm", 10, 90, 2);

	GradeBook toBeTestedObject(allocationManager, studentManager, studentGradesManager);
	CPPUNIT_ASSERT(toBeTestedObject.getFinalGradeForStudentByTeacher("Sally", "Grahm") == 90);
}

void TestGradeBook::calculateGradeWithoutExam()
{
	StudentManager studentManager;
	studentManager.addStudent("Sally");
	StudentGradesManager studentGradesManager(studentManager);
	studentGradesManager.addStudentsGradeScore("Sally", E_ASSIGNMENT, 85);
	studentGradesManager.addStudentsGradeScore("Sally", E_ASSIGNMENT, 88);
	studentGradesManager.addStudentsGradeScore("Sally", E_OPTIONAL_ASSIGNMENT);
	studentGradesManager.addStudentsGradeScore("Sally", E_ASSIGNMENT, 92);

	AllocationManager allocationManager;
	allocationManager.addAllocation("Tom", 10.1, 89.9, 2);

	GradeBook toBeTestedObject(allocationManager, studentManager, studentGradesManager);
	CPPUNIT_ASSERT(toBeTestedObject.getFinalGradeForStudentByTeacher("Sally", "Tom") == 90.33F);
}

void TestGradeBook::calculateGradeWithExam()
{
	StudentManager studentManager;
	studentManager.addStudent("Sally");
	StudentGradesManager studentGradesManager(studentManager);
	studentGradesManager.addStudentsGradeScore("Sally", E_ASSIGNMENT, 85);
	studentGradesManager.addStudentsGradeScore("Sally", E_ASSIGNMENT, 88);
	studentGradesManager.addStudentsGradeScore("Sally", E_OPTIONAL_ASSIGNMENT);
	studentGradesManager.addStudentsGradeScore("Sally", E_ASSIGNMENT, 92);
	studentGradesManager.addStudentsGradeScore("Sally", E_EXAM, 91);

	AllocationManager allocationManager;
	allocationManager.addAllocation("Tom", 10.1, 89.9, 2);

	GradeBook toBeTestedObject(allocationManager, studentManager, studentGradesManager);
	CPPUNIT_ASSERT(toBeTestedObject.getFinalGradeForStudentByTeacher("Sally", "Tom") == 90.93F);
}


int main(int argc, char **argv)
{
	CppUnit::TextUi::TestRunner runner;
	runner.addTest(TestGradeBook::suite() );
	runner.run();
	return 0;
}

