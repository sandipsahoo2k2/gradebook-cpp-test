#include "../src/StudentGradesManager.hpp"
#include "../src/StudentManager.hpp"
#include <cppunit/TestFixture.h>
#include <cppunit/TestAssert.h>
#include <cppunit/TestCaller.h>
#include <cppunit/TestSuite.h>
#include <cppunit/ui/text/TestRunner.h>

class TestStudentGradesManager:  public CppUnit::TestFixture {
public:
   static CppUnit::Test *suite()
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

   void setUp()
   {
   }

   void tearDown()
   {
   }

private:

protected:

  void addStudentGrade()
  {
   	StudentManager studentManager;
	studentManager.addStudent("Sally");
	StudentGradesManager toBeTestedObject(studentManager);
	toBeTestedObject.addGradeScore("Sally", E_EXAM, 80.1);
	toBeTestedObject.addGradeScore("Sally", E_EXAM, 81.1);
	toBeTestedObject.addGradeScore("Sally", E_ASSIGNMENT, 80.1);
	CPPUNIT_ASSERT(toBeTestedObject.getExams("Sally").size() == 2);
	CPPUNIT_ASSERT(toBeTestedObject.getAssignments("Sally").size() == 1);
  }

  void removeStudentGrade()
  {
   	StudentManager studentManager;
	studentManager.addStudent("Sally");
	StudentGradesManager toBeTestedObject(studentManager);
	toBeTestedObject.addGradeScore("Sally", E_EXAM, 80.1);
	toBeTestedObject.addGradeScore("Sally", E_EXAM, 83.1);
	toBeTestedObject.addGradeScore("Sally", E_OPTIONAL_ASSIGNMENT, 80.1);
	toBeTestedObject.removeGrades("Sally");
	CPPUNIT_ASSERT(toBeTestedObject.getGrades("Sally").size() == 0);
	CPPUNIT_ASSERT(toBeTestedObject.getExams("Sally").size() == 0);
  }
};

int main(int argc, char **argv)
{
	CppUnit::TextUi::TestRunner runner;
  	runner.addTest(TestStudentGradesManager::suite() );
  	runner.run();
  	return 0;
}

