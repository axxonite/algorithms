// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	int LongestNondecreasingSubsequenceLength(const vector<int>& A)
	{
		// max_length[i] holds the length of the longest nondecreasing subsequence of A[0, i].
		vector<int> max_length(A.size(), 1);
		// Find the longest non-decreasing sequence for the subarray [0..i].
		for (int i = 1; i < A.size(); ++i)
		{
			for (int j = 0; j < i; ++j)
			{
				// A[j] is less than A[i], so A[j] can definitely form a nondecreasing sequence with A[i]. Whatever longest nondecreasing sequence was found ending at j, can then be extended by one by adding A[i] to it.
				if (A[j] <= A[i])
					max_length[i] = max(max_length[i], max_length[j] + 1);
			}
		}
		// Return the longest length we found for all the subarray.
		// Notice the use of max_element, and the use of * since max_element returns an iterator.
		return *max_element(max_length.begin(), max_length.end());
	}
}