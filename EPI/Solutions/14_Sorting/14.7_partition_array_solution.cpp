// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"
#include "..\..\Shared.h"

namespace Solutions
{
	struct Person
	{
		int age;
		string name;
	};

	void GroupByAge(vector<Person>& people)
	{
		unordered_map<int, int> partitionCount;
		for (auto p : people)
			partitionCount[p.age]++;
		int index = 0;
		unordered_map<int, int> partitionIndices;
		for (auto it = partitionCount.begin(); it != partitionCount.end(); ++it)
			partitionIndices[it->first] = index, index += it->second;
		while (!partitionIndices.empty())
		{
			// Pretty tricky exchange between subarrays here.
			auto unpartitionedSrc = partitionIndices.begin(); // find a slot that hasn't been moved to its proper place yet.
			int age = people[unpartitionedSrc->second].age;
			auto partitionedDest = partitionIndices.find(age); // based on the age of the person currently in the from slot, the to slot that person would go to.
			swap(people[unpartitionedSrc->second], people[partitionedDest->second]); // swap it to the to slot.
			if (--partitionCount[age] == 0)
				partitionIndices.erase(partitionedDest);
			else partitionedDest->second++;
		}
	}
}