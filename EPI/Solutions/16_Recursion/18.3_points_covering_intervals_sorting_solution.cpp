// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	struct Interval
	{
		int left, right;
	};

	vector<int> FindMinimumVisits(vector<Interval> intervals)
	{
		if (intervals.empty())
			return {};

		// Sort intervals based on the right endpoints.
		sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b) { return a.right < b.right; });
		vector<int> result;
		result.emplace_back(intervals[0].right);
		for (int i = 1; i < intervals.size(); ++i)
		{
			if (intervals[i].left > result.back())
				result.emplace_back(intervals[i].right);
		}
		return result;
	}
}
