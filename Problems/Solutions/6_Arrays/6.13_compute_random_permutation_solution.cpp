// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"
#include "Solutions/6_Arrays/6.11_offline_sampling_solution.h"

namespace Solutions
{
	vector<int> ComputeRandomPermutation(int n)
	{
		vector<int> permutation(n);
		// Initializes permutation to 0, 1, 2, ..., n - 1.
		iota(permutation.begin(), permutation.end(), 0);
		RandomSampling(permutation.size(), permutation);
		return permutation;
	}
}
