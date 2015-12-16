#include "AbstractGrade.hpp"
#include "Types.hpp"
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

AbstractGrade::AbstractGrade(double score):score(score)
{
	type = E_INVALID;
	optional = false;
	id = 0;
}

AbstractGrade::~AbstractGrade()
{
}

EGradeType AbstractGrade::getType() const
{
	return type;
}

void AbstractGrade::setId(int id)
{
	this->id = id;
}

int AbstractGrade::getId() const
{
	return id;
}

double AbstractGrade::getScore() const
{
	return score;
}

int AbstractGrade::isOptional() const
{
	return optional;
}
