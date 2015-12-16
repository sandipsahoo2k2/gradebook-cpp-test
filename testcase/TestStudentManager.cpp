#include "TestStudentManager.hpp"

CppUnit::Test *TestStudentManager::suite()
{
	CppUnit::TestSuite *suiteOfTests = new CppUnit::TestSuite( "TestStudentManager" );
	suiteOfTests->addTest( new CppUnit::TestCaller<TestStudentManager>(
				"Add Student",
				&TestStudentManager::addStudent) );
	suiteOfTests->addTest( new CppUnit::TestCaller<TestStudentManager>(
				"Remove Remove",
				&TestStudentManager::removeStudent) );
	return suiteOfTests;
}

void TestStudentManager::setUp()
{
	toBeTestedObject = new StudentManager();
}

void TestStudentManager::tearDown()
{
	delete toBeTestedObject;
}

void TestStudentManager::addStudent()
{
	toBeTestedObject->addStudent(std::string("Sally"));
	toBeTestedObject->addStudent(std::string("Sandeep"));
	CPPUNIT_ASSERT(toBeTestedObject->getStudents().size() == 2);
}

void TestStudentManager::removeStudent()
{
	toBeTestedObject->addStudent(std::string("Sally"));
	toBeTestedObject->removeStudent(std::string("Sally"));
	CPPUNIT_ASSERT(toBeTestedObject->getStudents().size() == 0);
}

int main(int argc, char **argv)
{
	CppUnit::TextUi::TestRunner runner;
	runner.addTest(TestStudentManager::suite() );
	runner.run();
	return 0;
}

