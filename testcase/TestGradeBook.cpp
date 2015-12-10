#include "../src/GradeBook.hpp"
#include <cppunit/TestFixture.h>
#include <cppunit/TestAssert.h>
#include <cppunit/TestCaller.h>
#include <cppunit/TestSuite.h>
#include <cppunit/ui/text/TestRunner.h>

class TestGradeBook:  public CppUnit::TestFixture {
public:
   static CppUnit::Test *suite()
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

protected:

  void checkGradeAvailable()
  {
	StudentManager studentManager;
	studentManager.addStudent("Sally");
        StudentGradesManager studentGradesManager(studentManager);
	studentGradesManager.addGradeScore("Sally", E_EXAM, 80.1);
	studentGradesManager.addGradeScore("Sally", E_EXAM, 80.1);

        AllocationManager allocationManager;
        allocationManager.addAllocation("Grahm", 10, 90, 2);

	GradeBook toBeTestedObject(allocationManager, studentManager, studentGradesManager);
	CPPUNIT_ASSERT(toBeTestedObject.hasValidGrade("Sally", "Grahm") == true);
	CPPUNIT_ASSERT(toBeTestedObject.hasValidGrade("Sally", "Greg") == false);
  }

  void calculateSimpleGrade()
  {
	StudentManager studentManager;
	studentManager.addStudent("Sally");
        StudentGradesManager studentGradesManager(studentManager);
	studentGradesManager.addGradeScore("Sally", E_EXAM, 100);
	studentGradesManager.addGradeScore("Sally", E_EXAM, 100);

        AllocationManager allocationManager;
        allocationManager.addAllocation("Grahm", 10, 90, 2);

	GradeBook toBeTestedObject(allocationManager, studentManager, studentGradesManager);
	CPPUNIT_ASSERT(toBeTestedObject.getGrade("Sally", "Grahm") == 90);
  }

  void calculateGradeWithoutExam()
  {
	StudentManager studentManager;
	studentManager.addStudent("Sally");
        StudentGradesManager studentGradesManager(studentManager);
	studentGradesManager.addGradeScore("Sally", E_ASSIGNMENT, 85);
	studentGradesManager.addGradeScore("Sally", E_ASSIGNMENT, 88);
	studentGradesManager.addGradeScore("Sally", E_OPTIONAL_ASSIGNMENT);
	studentGradesManager.addGradeScore("Sally", E_ASSIGNMENT, 92);

        AllocationManager allocationManager;
        allocationManager.addAllocation("Tom", 10.1, 89.9, 2);

	GradeBook toBeTestedObject(allocationManager, studentManager, studentGradesManager);
	CPPUNIT_ASSERT(toBeTestedObject.getGrade("Sally", "Tom") == 90.33F);
  }

  void calculateGradeWithExam()
  {
        StudentManager studentManager;
        studentManager.addStudent("Sally");
        StudentGradesManager studentGradesManager(studentManager);
        studentGradesManager.addGradeScore("Sally", E_ASSIGNMENT, 85);
        studentGradesManager.addGradeScore("Sally", E_ASSIGNMENT, 88);
        studentGradesManager.addGradeScore("Sally", E_OPTIONAL_ASSIGNMENT);
        studentGradesManager.addGradeScore("Sally", E_ASSIGNMENT, 92);
	studentGradesManager.addGradeScore("Sally", E_EXAM, 91);

        AllocationManager allocationManager;
        allocationManager.addAllocation("Tom", 10.1, 89.9, 2);

        GradeBook toBeTestedObject(allocationManager, studentManager, studentGradesManager);
        CPPUNIT_ASSERT(toBeTestedObject.getGrade("Sally", "Tom") == 90.93F);
  }

};

int main(int argc, char **argv)
{
	CppUnit::TextUi::TestRunner runner;
  	runner.addTest(TestGradeBook::suite() );
  	runner.run();
  	return 0;
}

