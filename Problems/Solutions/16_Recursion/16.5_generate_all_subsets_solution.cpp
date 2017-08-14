// Copyright (c) 2013 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	void DirectedCombinations(int n, int k, int offset, vector<int>* partial_combination, vector<vector<int>>* result)
	{
		// Tricky: offset is the lowest number in the sequence that we about to add to the partial combination, because the partial combination
		// would already contain all lower numbers than the offset given. That way we don't add duplicates to the subset.
		if (partial_combination->size() == k)
		{
			// we have a full combination of size k, add it and return.
			result->emplace_back(*partial_combination);
			return;
		}

		// Generate remaining combinations over {offset, ..., n - 1} of size num_remaining.
		const int num_remaining = k - int(partial_combination->size());
		// test i <= n in case k is greater than n.
		// TRICKY: test num_remaining + i - 1 <= n to check that the sum of the count of numbers we need to add (num_remaining), 
		// plus the numbers we've already used up (i), minus one since the first number starts at 1.
		for (int i = offset; i <= n && num_remaining + i - 1 <= n; ++i)
		{
			// Add i as the next element in the partial combination.
			partial_combination->emplace_back(i);
			// Enumerate the remaining elements to finish a combination of size k.
			DirectedCombinations(n, k, i + 1, partial_combination, result);
			// Pop i back so we can replace it with i + 1 on the next iteration.
			partial_combination->pop_back();
		}
	}
	
		vector<vector<int>> Combinations(int n, int k)
	{
		vector<vector<int>> result;
		// Numbers in the set start at 1 so start offset at 1.
		// Note the use of make_unique here. Not sure that this is necessary? why not just put it on the stack?
		DirectedCombinations(n, k, 1, make_unique<vector<int>>().get(), &result);
		return result;
	}


}