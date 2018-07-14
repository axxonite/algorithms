// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	// As a reminder, a new "pillar" is a building that blocks the last pillar, that is, is shorter than the last pillar.
	bool IsShorterPillarOrReachEnd(const vector<int>& heights, int curr_idx, int last_pillar_idx)
	{
		return curr_idx < heights.size() ? heights[curr_idx] <= heights[last_pillar_idx] : true;
	}

	int CalculateLargestRectangle(const vector<int>& heights)
	{
		stack<int> pillar_indices;
		int max_rectangle_area = 0;
		// By iterating to heights.size() instead of heights.size() - 1, we can uniformly handle the computation of the width of the rectangle.
		for (int i = 0; i <= heights.size(); ++i)
		{
			// Don't forget to check if we have no pillar indices yet, in which case we need to add this new building as our first pillar.
			while (!pillar_indices.empty() && IsShorterPillarOrReachEnd(heights, i, pillar_indices.top()))
			{
				// this is a pillar that is shorter or equal to the last pillar.
				int height = heights[pillar_indices.top()]; // height of last pillar.
				pillar_indices.pop(); // remove last pillar - our new rectangle will extended from the previous pillar to the new pillar we just found.
				int width = pillar_indices.empty() ? i : i - pillar_indices.top() - 1; // Calculate width of rectangle supported by the new pillar set.
				max_rectangle_area = max(max_rectangle_area, height * width); // Compute area.
			}
			pillar_indices.emplace(i); // Add new pillar.
		}
		return max_rectangle_area;
	}
}
