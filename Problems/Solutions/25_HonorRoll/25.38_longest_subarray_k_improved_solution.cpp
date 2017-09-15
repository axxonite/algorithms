// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	int FindLongestSubarrayLessEqualK(const vector<int> &A, int k)
	{
		// Builds the prefix sum according to A (P)
		vector<int> prefix_sum;
		// Note the use of partial_sum here.
		partial_sum(A.cbegin(), A.cend(), back_inserter(prefix_sum));

		// Early out: return if the sum of A is smaller than or equal to k.
		if (prefix_sum.back() <= k)
			return int(A.size());

		// Builds min_prefix_sum (Q)
		vector<int> min_prefix_sum(A.size());
		min_prefix_sum.back() = prefix_sum.back(); // Q for last element is always P[n-1].
		for (int i = int(min_prefix_sum.size()) - 2; i >= 0; --i)
			min_prefix_sum[i] = min(prefix_sum[i], min_prefix_sum[i + 1]);

		int a = 0, b = 0, max_length = 0;
		while (a < A.size() && b < A.size())
		{
			// Note the exceptional case for when a is zero.
			// The a - 1 is important here. We want to include a, so we need to subtract the prefix that ends at a -1.
			int min_curr_sum = a > 0 ? min_prefix_sum[b] - prefix_sum[a - 1] : min_prefix_sum[b];
			if (min_curr_sum <= k)
			{
				int curr_length = b - a + 1; // Add one so that when a and b coincide this actually gives a length of one.
				if (curr_length > max_length)
					max_length = curr_length;
				++b;
			}
			// min_curr_sum > k.
			else ++a;
		}
		return max_length;
	}
}
