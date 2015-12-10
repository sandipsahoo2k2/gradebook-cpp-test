#include "../src/StudentManager.hpp"
#include <string>
#include <cppunit/TestFixture.h>
#include <cppunit/TestAssert.h>
#include <cppunit/TestCaller.h>
#include <cppunit/TestSuite.h>
#include <cppunit/ui/text/TestRunner.h>

class TestStudentManager:  public CppUnit::TestFixture {
public:
   static CppUnit::Test *suite()
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

   void setUp()
   {
	toBeTestedObject = new StudentManager();
   }

   void tearDown()
   {
	delete toBeTestedObject;
   }

private:
   StudentManager *toBeTestedObject;

protected:

  void addStudent()
  {
	toBeTestedObject->addStudent(std::string("Sally"));
	toBeTestedObject->addStudent(std::string("Sandeep"));
	CPPUNIT_ASSERT(toBeTestedObject->getStudents().size() == 2);
  }

  void removeStudent()
  {
	toBeTestedObject->addStudent(std::string("Sally"));
	toBeTestedObject->removeStudent(std::string("Sally"));
	CPPUNIT_ASSERT(toBeTestedObject->getStudents().size() == 0);
  }
};

int main(int argc, char **argv)
{
	CppUnit::TextUi::TestRunner runner;
  	runner.addTest(TestStudentManager::suite() );
  	runner.run();
  	return 0;
}

