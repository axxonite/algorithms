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
			auto dupIndex = mostRecentOccurence.emplace(a[i], i);
			// Defer updating dup_idx until we see a duplicate.
			if (!dupIndex.second)
			{
				// a[i] appeared before. Did it appear in the longest current subarray?
				if (dupIndex.first->second >= subArrayStart)
				{
					result = max(result, i - subArrayStart);
					subArrayStart = dupIndex.first->second + 1;
				}
				dupIndex.first->second = i;
			}
		}
		return max(result, a.size() - subArrayStart);
	}
}
