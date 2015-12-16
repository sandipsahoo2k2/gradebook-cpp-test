#include "TestStudentGradesManager.hpp"

CppUnit::Test *TestStudentGradesManager::suite()
{
	CppUnit::TestSuite *suiteOfTests = new CppUnit::TestSuite( "TestStudentGradesManager" );
	suiteOfTests->addTest( new CppUnit::TestCaller<TestStudentGradesManager>(
				"Add grade score",
				&TestStudentGradesManager::addStudentGrade) );
	suiteOfTests->addTest( new CppUnit::TestCaller<TestStudentGradesManager>(
				"Remove grade score",
				&TestStudentGradesManager::removeStudentGrade) );
	return suiteOfTests;
}

void TestStudentGradesManager::setUp()
{
}

void TestStudentGradesManager::tearDown()
{
}

void TestStudentGradesManager::addStudentGrade()
{
	StudentManager studentManager;
	studentManager.addStudent("Sally");
	StudentGradesManager toBeTestedObject(studentManager);
	toBeTestedObject.addStudentsGradeScore("Sally", E_EXAM, 80.1);
	toBeTestedObject.addStudentsGradeScore("Sally", E_EXAM, 81.1);
	toBeTestedObject.addStudentsGradeScore("Sally", E_ASSIGNMENT, 80.1);
	CPPUNIT_ASSERT(toBeTestedObject.getStudentsExams("Sally").size() == 2);
	CPPUNIT_ASSERT(toBeTestedObject.getStudentsAssignments("Sally").size() == 1);
}

void TestStudentGradesManager::removeStudentGrade()
{
	StudentManager studentManager;
	studentManager.addStudent("Sally");
	StudentGradesManager toBeTestedObject(studentManager);
	toBeTestedObject.addStudentsGradeScore("Sally", E_EXAM, 80.1);
	toBeTestedObject.addStudentsGradeScore("Sally", E_EXAM, 83.1);
	toBeTestedObject.addStudentsGradeScore("Sally", E_OPTIONAL_ASSIGNMENT, 80.1);
	toBeTestedObject.removeStudentsGrades("Sally");
	CPPUNIT_ASSERT(toBeTestedObject.getStudentsGrades("Sally").size() == 0);
	CPPUNIT_ASSERT(toBeTestedObject.getStudentsExams("Sally").size() == 0);
}

int main(int argc, char **argv)
{
	CppUnit::TextUi::TestRunner runner;
	runner.addTest(TestStudentGradesManager::suite() );
	runner.run();
	return 0;
}

