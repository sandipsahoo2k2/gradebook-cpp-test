#include "../src/StudentTestsManager.hpp"
#include "../src/StudentManager.hpp"
#include <cppunit/TestFixture.h>
#include <cppunit/TestAssert.h>
#include <cppunit/TestCaller.h>
#include <cppunit/TestSuite.h>
#include <cppunit/ui/text/TestRunner.h>

class TestStudentTestsManager:  public CppUnit::TestFixture {
public:
   static CppUnit::Test *suite()
   {
     CppUnit::TestSuite *suiteOfTests = new CppUnit::TestSuite( "TestStudentTestsManager" );
     suiteOfTests->addTest( new CppUnit::TestCaller<TestStudentTestsManager>(
                                    "Add Score",
                                    &TestStudentTestsManager::addStudentTest) );
     suiteOfTests->addTest( new CppUnit::TestCaller<TestStudentTestsManager>(
                                    "Remove score",
                                    &TestStudentTestsManager::removeStudentTest) );
     return suiteOfTests;
   }

   void setUp()
   {
   }

   void tearDown()
   {
   }

private:

protected:

  void addStudentTest()
  {
   	StudentManager studentManager;
	studentManager.addStudent("Sally");
	StudentTestsManager toBeTestedObject(studentManager);
	toBeTestedObject.addTestScore("Sally", E_TEST_EXAM, 80.1);
	toBeTestedObject.addTestScore("Sally", E_TEST_EXAM, 81.1);
	toBeTestedObject.addTestScore("Sally", E_TEST_ASSIGNMENT, 80.1);
	CPPUNIT_ASSERT(toBeTestedObject.getExams("Sally").size() == 2);
	CPPUNIT_ASSERT(toBeTestedObject.getAssignments("Sally").size() == 1);
  }

  void removeStudentTest()
  {
   	StudentManager studentManager;
	studentManager.addStudent("Sally");
	StudentTestsManager toBeTestedObject(studentManager);
	toBeTestedObject.addTestScore("Sally", E_TEST_EXAM, 80.1);
	toBeTestedObject.addTestScore("Sally", E_TEST_EXAM, 83.1);
	toBeTestedObject.addTestScore("Sally", E_TEST_OPTIONAL_ASSIGNMENT, 80.1);
	toBeTestedObject.removeTests("Sally");
	CPPUNIT_ASSERT(toBeTestedObject.getTests("Sally").size() == 0);
	CPPUNIT_ASSERT(toBeTestedObject.getExams("Sally").size() == 0);
  }
};

int main(int argc, char **argv)
{
	CppUnit::TextUi::TestRunner runner;
  	runner.addTest(TestStudentTestsManager::suite() );
  	runner.run();
  	return 0;
}

