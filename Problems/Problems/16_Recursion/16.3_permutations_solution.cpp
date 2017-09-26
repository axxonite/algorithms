// Copyright (c) 2013 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	void DirectedPermutations(int i, vector<int>& a, vector<vector<int>>& result)
	{
		// We need two elements to swap, so stop iterating once we've reached a.size() - 1, since there are no further elements to swap with beyond the current one.
		if (i == a.size() - 1)
		{
			result.emplace_back(a);
			return;
		}

		// Try every possibility for a[i], and recursively call the function to generate all permutations from the remaining elements for the remaining suffix. The prefix a[0..i - 1] is constant during this iteration.
		// We must start iterating from i, not i + 1, so that we include the permutation that doesn't do any swapping.
		for (int j = i; j < a.size(); ++j)
		{
			swap(a[i], a[j]);
			// Generate all permutations for a[i + 1, a.size() - 1].
			// Note that we use increment i, not j. This means we are swapping i with every other element after it in the array, and generating permutations on the rest of the array.
			DirectedPermutations(i + 1, a, result);
			swap(a[i], a[j]);
		}
	}

	vector<vector<int>> Permutations(vector<int> a)
	{
		vector<vector<int>> result;
		DirectedPermutations(0, a, result);
		return result;
	}
}
