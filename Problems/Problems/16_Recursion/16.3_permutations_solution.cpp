// Copyright (c) 2013 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	void DirectedPermutations(int swapDest, vector<int>& a, vector<vector<int>>& result)
	{
		// We need two elements to swap, so stop iterating once we've reached a.size() - 1, since there are no further elements to swap with beyond the current one.
		if (swapDest == a.size() - 1)
		{
			result.emplace_back(a);
			return;
		}

		// Try every possibility for a[swapDest], and recursively call the function to generate all permutations from the remaining elements for the remaining suffix. The prefix a[0..swapDest - 1] is constant during this iteration.
		// We must start iterating from swapDest, not swapDest + 1, so that we include the permutation that doesn't do any swapping.
		for (int i = swapDest; i < a.size(); ++i)
		{
			swap(a[swapDest], a[i]);
			// Generate all permutations for a[swapDest + 1, a.size() - 1].
			// Note that we use increment swapDest, not j. This means we are swapping swapDest with every other element after it in the array, and generating permutations on the rest of the array.
			DirectedPermutations(swapDest + 1, a, result);
			swap(a[swapDest], a[i]);
		}
	}

	vector<vector<int>> Permutations(vector<int> a)
	{
		vector<vector<int>> result;
		DirectedPermutations(0, a, result);
		return result;
	}
}
