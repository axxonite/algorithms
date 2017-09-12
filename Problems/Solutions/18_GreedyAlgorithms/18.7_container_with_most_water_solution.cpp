// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	int GetMaxTrappedWater(const vector<int>& heights)
	{
		int i = 0, j = heights.size() - 1, max_water = 0;
		while (i < j)
		{
			int width = j - i;
			max_water = max(max_water, width * min(heights[i], heights[j]));
			if (heights[i] > heights[j])
				--j;
			else
				++i; // heights[i] <= heights[j].
		}
		return max_water;
	}
}
