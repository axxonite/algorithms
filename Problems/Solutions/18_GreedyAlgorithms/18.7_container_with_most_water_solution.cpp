// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	int GetMaxTrappedWater(const vector<int>& heights)
	{
		// Start two iterators at both ends of the array.
		int i = 0, j = heights.size() - 1, maxWater = 0;
		while (i < j)
		{
			int width = j - i; // IMPORTANT: there is no +1 needed here. If the right side is at 10 and the left side is at 0, then we have only ten units of width, not 11 as I previously thought.
			// Max water is the minimum of the height on either side.
			maxWater = max(maxWater, width * min(heights[i], heights[j]));
			// if the height at i is greater, then j is the limiting side, so decrease j.
			if (heights[i] > heights[j])
				--j;
			else
				++i; // heights[i] <= heights[j].
		}
		return maxWater;
	}
}
