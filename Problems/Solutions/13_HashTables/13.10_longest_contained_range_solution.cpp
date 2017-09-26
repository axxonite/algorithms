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

			// Look for the next values below a.
			int low = a - 1;
			while (unprocessed.count(low))
			{
				unprocessed.erase(low);
				--low;
			}

			// Look for the next values above a.
			int high = a + 1;
			while (unprocessed.count(high))
			{
				unprocessed.erase(high);
				++high;
			}

			// note the - 1 here, since if high == low the range still has a length of 1.
			maxIntervalSize = max(maxIntervalSize, high - low - 1);
		}
		return maxIntervalSize;
	}
}
