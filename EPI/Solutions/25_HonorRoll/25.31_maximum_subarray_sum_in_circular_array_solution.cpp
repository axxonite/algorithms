// Copyright (c) 2013 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	int FindOptimumSubarrayUsingComp(const vector<int>& A, const int& (*comp)(const int&, const int&))
	{
		// "till" computes the best value for the subarray from 0 to i. "overall" keeps track of the best result we found in all the subarrays so far.
		int till = 0, overall = 0;
		for (int a : A)
		{
			// The logic for this here is, if the sum of the entries before i is less than a, its better to start the subarray from a instead.
			// Another way to see it is, any number in the prefix that makes the prefix even smaller, needs to be discarded for a max subarray result.
			// Once a[i] is greater than the subarray sum ("till"), then the we have found the minimum subarray starting from 0, and the remaining entries after that minimum subarray, will form the maximum subarray.
			// I'm still unsure how to prove this, exactly, and the way it's written out here is very counter-intuitive.
			till = comp(a, a + till);
			overall = comp(overall, till);
		}
		return overall;
	}

	int MaxSubarraySumInCircular(const vector<int>& A)
	{
		// Finds the max in non-circular case and circular case.
		return max(FindOptimumSubarrayUsingComp(A, max), // Non-circular case.
		           accumulate(A.cbegin(), A.cend(), 0) - FindOptimumSubarrayUsingComp(A, min)); // Circular case.
	}
}