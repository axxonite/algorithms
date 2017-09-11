// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	// Returns a random k-sized subset of {0, 1, ..., n - 1}.
	vector<int> RandomSubset(int n, int k)
	{
		unordered_map<int, int> changedElements;
		default_random_engine seed((random_device())());
		for (int i = 0; i < k; ++i)
		{
			// Generate a random index in [i, n - 1].
			int randIndex = uniform_int_distribution<int>{ i, n - 1 }(seed);
			auto ptr1 = changedElements.find(randIndex), ptr2 = changedElements.find(i);
			if (ptr1 == changedElements.end() && ptr2 == changedElements.end())
			{
				changedElements[randIndex] = i;
				changedElements[i] = randIndex;
			}
			else if (ptr1 == changedElements.end() && ptr2 != changedElements.end())
			{
				changedElements[randIndex] = ptr2->second;
				ptr2->second = randIndex;
			}
			else if (ptr1 != changedElements.end() && ptr2 == changedElements.end())
			{
				changedElements[i] = ptr1->second;
				ptr1->second = i;
			}
			else
			{
				int temp = ptr2->second;
				changedElements[i] = ptr1->second;
				changedElements[randIndex] = temp;
			}
		}

		vector<int> result;
		for (int i = 0; i < k; ++i)
			result.emplace_back(changedElements[i]);
		return result;
	}
}
