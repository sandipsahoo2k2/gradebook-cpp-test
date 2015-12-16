#include "../src/AllocationManager.hpp"
#include <cppunit/TestFixture.h>
#include <cppunit/TestAssert.h>
#include <cppunit/TestCaller.h>
#include <cppunit/TestSuite.h>
#include <cppunit/ui/text/TestRunner.h>

class TestAllocationManager:  public CppUnit::TestFixture {
	public:
		static CppUnit::Test *suite() ;
		void setUp() ;
		void tearDown() ;

	private:
		AllocationManager *toBeTestedObject;

	protected:

		void addAllocation() ;
		void checkAllocation() ;
};

