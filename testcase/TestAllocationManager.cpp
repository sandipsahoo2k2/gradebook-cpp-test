#include "TestAllocationManager.hpp"

CppUnit::Test* TestAllocationManager::suite()
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

void TestAllocationManager::setUp()
{
	toBeTestedObject = new AllocationManager();
}

void TestAllocationManager::tearDown()
{
	delete toBeTestedObject;
}

void TestAllocationManager::addAllocation()
{
	toBeTestedObject->addAllocation("Grahm", 10, 90, 2);
	toBeTestedObject->addAllocation("Sandy", 11, 89, 3);
	CPPUNIT_ASSERT(toBeTestedObject->getAllocations().size() == 2);
}

void TestAllocationManager::checkAllocation()
{
	toBeTestedObject->addAllocation("Grahm", 10, 90, 2);
	toBeTestedObject->addAllocation("Sandy", 10.5, 89.5, 3);
	AllocationPtr allocation = toBeTestedObject->getAllocation("Sandy");
	CPPUNIT_ASSERT(allocation->getAssignmentAllocation() == 10.5);
}

int main(int argc, char **argv)
{
	CppUnit::TextUi::TestRunner runner;
	runner.addTest(TestAllocationManager::suite() );
	runner.run();
	return 0;
}

