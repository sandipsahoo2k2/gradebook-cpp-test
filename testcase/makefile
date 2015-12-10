CPP_DIR = ../src
TEST_DIR = ../../cppunit-1.12.1/include
BIN_DIR = ../obj

TestBinaries : TestStudentManager.o TestStudentGradesManager.o TestAllocationManager.o TestGradeBook.o
	g++ -o TestStudentManager.out TestStudentManager.o $(BIN_DIR)/Student.o $(BIN_DIR)/StudentManager.o /usr/local/lib/libcppunit.a
	g++ -o TestStudentGradesManager.out TestStudentGradesManager.o $(BIN_DIR)/StudentManager.o $(BIN_DIR)/Student.o $(BIN_DIR)/AbstractGrade.o $(BIN_DIR)/Exam.o $(BIN_DIR)/Assignment.o $(BIN_DIR)/OptionalAssignment.o $(BIN_DIR)/StudentGradesManager.o /usr/local/lib/libcppunit.a
	g++ -o TestAllocationManager.out TestAllocationManager.o $(BIN_DIR)/AllocationManager.o $(BIN_DIR)/Allocation.o /usr/local/lib/libcppunit.a
	g++ -o TestGradeBook.out TestGradeBook.o $(BIN_DIR)/GradeBook.o $(BIN_DIR)/AllocationManager.o $(BIN_DIR)/Allocation.o $(BIN_DIR)/StudentManager.o $(BIN_DIR)/Student.o $(BIN_DIR)/StudentGradesManager.o $(BIN_DIR)/AbstractGrade.o $(BIN_DIR)/Exam.o $(BIN_DIR)/Assignment.o $(BIN_DIR)/OptionalAssignment.o /usr/local/lib/libcppunit.a
	mv *.o obj/
	mv *.out bin/

TestStudentManager.o : TestStudentManager.cpp $(CPP_DIR)/StudentManager.hpp
	g++ -std=c++11 -c TestStudentManager.cpp -I$(TEST_DIR)

TestStudentGradesManager.o : TestStudentGradesManager.cpp $(CPP_DIR)/StudentGradesManager.hpp
	g++ -std=c++11 -c TestStudentGradesManager.cpp -I$(TEST_DIR)

TestAllocationManager.o : TestAllocationManager.cpp $(CPP_DIR)/AllocationManager.hpp
	g++ -std=c++11 -c TestAllocationManager.cpp -I$(TEST_DIR)

TestGradeBook.o : TestGradeBook.cpp $(CPP_DIR)/GradeBook.hpp
	g++ -std=c++11 -c TestGradeBook.cpp -I$(TEST_DIR)

clean: 
	rm obj/*.o bin/*.out 

