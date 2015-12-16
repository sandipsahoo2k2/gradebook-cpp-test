#include "../src/StudentGradesManager.hpp"
#include "../src/StudentManager.hpp"
#include <cppunit/TestFixture.h>
#include <cppunit/TestAssert.h>
#include <cppunit/TestCaller.h>
#include <cppunit/TestSuite.h>
#include <cppunit/ui/text/TestRunner.h>

class TestStudentGradesManager:  public CppUnit::TestFixture {
	public:
		static CppUnit::Test *suite() ;

		void setUp() ;

		void tearDown() ;

		void addStudentGrade() ;

		void removeStudentGrade() ;

};

