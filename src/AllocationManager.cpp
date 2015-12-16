#include "AllocationManager.hpp"
#include <sstream>

AllocationManager::AllocationManager()
{
}

AllocationManager::~AllocationManager()
{
}

void AllocationManager::addAllocation(const std::string& teacherName, double assignmentAllocation, double examAllocation, double optionalAssignmentAllocation)
{
	AllocationPtr allocation(new Allocation(assignmentAllocation, examAllocation, optionalAssignmentAllocation));
	allocations[teacherName] = allocation;
}

void AllocationManager::removeAllocation(const std::string& teacherName)
{
	allocations.erase(teacherName);	
}

std::string AllocationManager::toString() const
{
	std::ostringstream ss;
	ss << "\nPrinitng Allocations DB" << std::endl;
	for(std::map<std::string, AllocationPtr>::const_iterator itr = allocations.begin(); itr != allocations.end(); ++itr)
	{
		ss << "\nAllocation for " << itr->first << " is " << *(itr->second) << std::endl;
	}
	ss << "\n\nEnd of Allocations DB" << std::endl;
	return std::string(ss.str());
}

AllocationPtr AllocationManager::getAllocation(const std::string& tecaherName) const
{
	AllocationPtr allocation = NULL ;
	std::map<std::string, AllocationPtr>::const_iterator itr = allocations.find(tecaherName);
	if(itr != allocations.end())
	{
		allocation = itr->second;
	}
	return allocation;
}
