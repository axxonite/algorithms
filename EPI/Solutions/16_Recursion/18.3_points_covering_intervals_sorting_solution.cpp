// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	struct Interval
	{
		int left, right;

		bool operator <(const Interval& rhs) const
		{
			return right < rhs.right;
		}
	};

	vector<int> FindMinimumVisits(vector<Interval> intervals)
	{
		if (intervals.empty())
			return {};

		// Sort intervals based on the right endpoints.
		sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b) { return a.right < b.right; });
		vector<int> visits;
		int lastVisitTime = intervals.front().right;
		visits.emplace_back(lastVisitTime);
		for (const Interval& interval : intervals)
		{
			if (interval.left > lastVisitTime)
			{
				// The current right endpoint, last_visit_time, will not cover any more intervals.
				lastVisitTime = interval.right;
				visits.emplace_back(lastVisitTime);
			}
		}
		return visits;
	}
}
