#include "AbstractTest.hpp"
#include "ITest.hpp"
#include "Types.hpp"
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

AbstractTest::AbstractTest(double score):score(score)
{
	type = E_TEST_EXAM;
	optional = false;
	id = 0;
}

AbstractTest::~AbstractTest()
{
}

ETestType AbstractTest::getType() const
{
	return type;
}

void AbstractTest::setId(int id)
{
	this->id = id;
}

int AbstractTest::getId() const
{
	return id;
}

double AbstractTest::getScore() const
{
	return score;
}

int AbstractTest::isOptional() const
{
        return optional;
}
