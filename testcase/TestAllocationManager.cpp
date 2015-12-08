#include "../src/AllocationManager.hpp"
#include <cppunit/TestFixture.h>
#include <cppunit/TestAssert.h>
#include <cppunit/TestCaller.h>
#include <cppunit/TestSuite.h>
#include <cppunit/ui/text/TestRunner.h>

class TestAllocationManager:  public CppUnit::TestFixture {
public:
   static CppUnit::Test *suite()
   {
     CppUnit::TestSuite *suiteOfTests = new CppUnit::TestSuite( "TestAllocationManager" );
     suiteOfTests->addTest( new CppUnit::TestCaller<TestAllocationManager>(
                                    "Add Allocation",
                                    &TestAllocationManager::addAllocation) );
     suiteOfTests->addTest( new CppUnit::TestCaller<TestAllocationManager>(
                                    "Check Allocation",
                                    &TestAllocationManager::checkAllocation) );
     return suiteOfTests;
   }

   void setUp()
   {
	toBeTestedObject = new AllocationManager();
   }

   void tearDown()
   {
	delete toBeTestedObject;
   }

private:
   AllocationManager *toBeTestedObject;

protected:

  void addAllocation()
  {
	toBeTestedObject->addAllocation("Grahm", 10, 90, 2);
	toBeTestedObject->addAllocation("Sandy", 11, 89, 3);
	CPPUNIT_ASSERT(toBeTestedObject->getAllocations().size() == 2);
  }

  void checkAllocation()
  {
	toBeTestedObject->addAllocation("Grahm", 10, 90, 2);
	toBeTestedObject->addAllocation("Sandy", 10.5, 89.5, 3);
	AllocationPtr allocation = toBeTestedObject->getAllocation("Sandy");
	CPPUNIT_ASSERT(allocation->getAssignmentAllocation() == 10.5);
  }
};

int main(int argc, char **argv)
{
	CppUnit::TextUi::TestRunner runner;
  	runner.addTest(TestAllocationManager::suite() );
  	runner.run();
  	return 0;
}

