#include "../src/StudentManager.hpp"
#include <string>
#include <cppunit/TestFixture.h>
#include <cppunit/TestAssert.h>
#include <cppunit/TestCaller.h>
#include <cppunit/TestSuite.h>
#include <cppunit/ui/text/TestRunner.h>

class TestStudentManager:  public CppUnit::TestFixture {

	public:
		static CppUnit::Test *suite() ;

		void setUp();

		void tearDown();
	private:
		StudentManager *toBeTestedObject;

	protected:

		void addStudent() ;

		void removeStudent() ;
};

