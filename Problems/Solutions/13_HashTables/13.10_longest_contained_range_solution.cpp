// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	int LongestContainedRange(const vector<int>& A)
	{
		// unprocessed_entries records the existence of each entry in A.
		unordered_set<int> unprocessed(A.begin(), A.end());

		int maxIntervalSize = 0;
		while (!unprocessed.empty())
		{
			int a = *unprocessed.begin();
			unprocessed.erase(a);

			// Finds the lower bound of the largest range containing a.
			int lower_bound = a - 1;
			while (unprocessed.count(lower_bound))
			{
				unprocessed.erase(lower_bound);
				--lower_bound;
			}

			// Finds the upper bound of the largest range containing a.
			int upper_bound = a + 1;
			while (unprocessed.count(upper_bound))
			{
				unprocessed.erase(upper_bound);
				++upper_bound;
			}

			maxIntervalSize = max(maxIntervalSize, upper_bound - lower_bound - 1);
		}
		return maxIntervalSize;
	}
}
