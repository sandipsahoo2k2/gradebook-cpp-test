#include "../src/GradeBook.hpp"
#include <memory>
#include <cppunit/TextTestRunner.h>
#include <cppunit/TestFixture.h>
#include <cppunit/TestAssert.h>
#include <cppunit/TestCaller.h>
#include <cppunit/TestSuite.h>
#include <cppunit/ui/text/TestRunner.h>

class TestGradeBook:  public CppUnit::TestFixture {
	public:
		static CppUnit::Test *suite() ;

	protected:

		void checkGradeAvailable();

		void calculateSimpleGrade();

		void calculateGradeWithoutExam();

		void calculateGradeWithExam();

};

