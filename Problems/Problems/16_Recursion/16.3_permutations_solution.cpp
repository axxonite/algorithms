// Copyright (c) 2013 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	void DirectedPermutations(int i, vector<int>& a, vector<vector<int>>& result)
	{
		if (i == a.size() - 1)
		{
			result.emplace_back(a);
			return;
		}

		// Try every possibility for a[i], and recursively call the function to generate all permutations from the remaining elements for the remaining suffix. The prefix a[0..i - 1] is constant during this iteration.
		for (int j = i; j < a.size(); ++j)
		{
			swap(a[i], a[j]);
			// Generate all permutations for a[i + 1, a.size() - 1].
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
