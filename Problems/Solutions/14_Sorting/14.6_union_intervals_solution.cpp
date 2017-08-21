// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	struct Interval
	{
	private:
		struct Endpoint
		{
			bool isClosed;
			int val;
		};

	public:
		bool operator<(const Interval& i) const
		{
			if (left.val != i.left.val)
				return left.val < i.left.val;
			// Left endpoints are equal, so now see if one is closed and the other open - closed intervals should appear first, which will ensure that two intervals with the same left side position but different open/close states, will result in a union with a closed state
			// at the left endpoint.
			return left.isClosed && !i.left.isClosed;
		}

		Endpoint left, right;
	};

	vector<Interval> UnionOfIntervals(vector<Interval> intervals)
	{
		// Empty input.
		if (intervals.empty())
			return {};

		// Sort intervals according to left endpoints of intervals.
		sort(intervals.begin(), intervals.end());
		vector<Interval> result;
		for (Interval i : intervals)
		{
			// most recently added interval is result.back(), current interval is i
			// Rules:
			// When we don't have any interval yet, we always add the new interval as its own interval.
			// if i's left is < last's right, or the endpoints coincide and either is closed, then check if i extends past last's right, by checking that i's right is > last's right or that i's right coincides with last's right and i's right is closed,
			// in which case extend the last interval by i's right end point. If the right endpoints coincide then the right endpoint will be closed, if it wasn't already.
			if (!result.empty() && (i.left.val < result.back().right.val || (i.left.val == result.back().right.val && (i.left.isClosed || result.back().right.isClosed))))
			{
				if (i.right.val > result.back().right.val || i.right.val == result.back().right.val && i.right.isClosed)
					result.back().right = i.right;
			}
			else
				result.emplace_back(i);
		}
		return result;
	}
}
