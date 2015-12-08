#include "Allocation.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

#ifndef _ALLOCATION_MANAGER_H_
#define _ALLOCATION_MANAGER_H_

class AllocationManager
{
	private:
		std::map<std::string, AllocationPtr> allocations;

	public:
		AllocationManager();
		~AllocationManager();

		void addAllocation(std::string teacherName, double assignmentAllocation, double examAllocation, double optionalAssignmentAllocation) ;

		void removeAllocation(std::string teacherName);
		
		std::string toString() const;
		
		AllocationPtr getAllocation(std::string tecaherName) const;
		
		const std::map<std::string, AllocationPtr>& getAllocations() const
		{
			return allocations;
		}

};

#endif
