// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	int LongestSubarrayWithDistinctEntries(const vector<int>& a)
	{
		// Records the most recent occurrences of each entry.
		unordered_map<int, size_t> mostRecentOccurence;
		size_t subArrayStart = 0, result = 0;
		for (size_t i = 0; i < a.size(); ++i)
		{
			// note that we can emplace, and if the value already exists, emplace will return false in the second member of the returned pair.
			auto dupIndex = mostRecentOccurence.emplace(a[i], i); // position of last instance of value a[i]
			// Defer updating dup_idx until we see a duplicate.
			if (!dupIndex.second) // already in table.
			{
				// a[i] appeared before. See if it appeared past the beginning of the current subarray.
				if (dupIndex.first->second >= subArrayStart)
				{
					result = max(result, i - subArrayStart); // no minus 1 here. Use start, not the retrieved location.
					subArrayStart = dupIndex.first->second + 1; // the new subarray now needs to start past the location of the last duplicate entry.
				}
				dupIndex.first->second = i; // update duplicate entry.
			}
		}
		return max(result, a.size() - subArrayStart); // don't forget to update the longest subarray continuing to the end of the intput array.
	}
}
