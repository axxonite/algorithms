// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	struct Interval
	{
		int left, right;
	};

	vector<Interval> AddInterval(const vector<Interval>& intervals, Interval newInterval)
	{
		vector<Interval> result;
		int i = 0;
		while (i < intervals.size() && intervals[i].right < newInterval.left)
			result.emplace_back(intervals[i++]);
		while (i < intervals.size() && intervals[i].left <= newInterval.right)
		{
			newInterval = { min(newInterval.left, intervals[i].left), max(newInterval.right, intervals[i].right) };
			i++;
		}
		result.emplace_back(newInterval);
		while (i < intervals.size())
			result.emplace_back(intervals[i++]);
		return result;
	}
}
