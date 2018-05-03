// Copyright (c) 2013 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	int FindOptimumSubarrayUsingComp(const vector<int>& A, const int& (*comp)(const int&, const int&))
	{
		// Kadane's algorithm.
		// Suppose we know the largest subarray sum ending at i. Call this sum B{i}. How do we compute B{i+1}?
		// Either B{i+1} includes B{i} as a prefix, or it doesn't. Thus B{i+1}=max(A{i+1},A{i+1}+B{i})
		int maxEndingHere = 0, overallMax = 0;
		for (int a : A)
		{
			maxEndingHere = comp(a, a + maxEndingHere);
			overallMax = comp(overallMax, maxEndingHere);
		}
		return overallMax;
	}

	int MaxSubarraySumInCircular(const vector<int>& A)
	{
		// Finds the max in non-circular case and circular case.
		return max(FindOptimumSubarrayUsingComp(A, max), // Non-circular case.
		           accumulate(A.cbegin(), A.cend(), 0) - FindOptimumSubarrayUsingComp(A, min)); // Circular case.
	}
}