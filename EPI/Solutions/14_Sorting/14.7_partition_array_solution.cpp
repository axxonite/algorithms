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
		unordered_map<int, int> counts;
		for (auto p : people)
			counts[p.age]++;
		int index = 0;
		unordered_map<int, int> indices;
		for (auto it = counts.begin(); it != counts.end(); ++it)
			indices[it->first] = index, index += it->second;
		while (!indices.empty())
		{
			// Pretty tricky exchange between subarrays here.
			auto from = indices.begin(); // find a slot that hasn't been moved to its proper place yet.
			auto to = indices.find(people[from->second].age); // based on the age of the person currently in the from slot, the to slot that person would go to.
			swap(people[from->second], people[to->second]); // swap it to the to slot.
			counts[people[to->second].age]--;
			if (counts[people[to->second].age] == 0)
				indices.erase(to);
			else to->second++;
		}
	}
}