// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	struct Rectangle;
	typedef vector<Rectangle> Skyline;

	struct Rectangle
	{
		int left, right, height;
	};

	typedef vector<Rectangle> Skyline;

	Skyline ComputeSkyline(const vector<Rectangle>& buildings)
	{
		// Find the extents on the left and the right so we can create an array of the appropriate size.
		int minLeft = numeric_limits<int>::max(), maxRight = numeric_limits<int>::min();
		for (const Rectangle& b : buildings)
			minLeft = min(minLeft, b.left), maxRight = max(maxRight, b.right);

		// Digitize the problem into an array.
		// Note: this doesn't seem like the most effective solution. We could sort the buildings edges to only update the building when we cross a building edge.
		// Keep a separate structure for each building so we can mark a building when we get past it. Put those structures in a max-heap to track the highest building.
		// If we get past a building and it's the top one on the heap, pop it from the heap along with any other buildings that have been marked when we got past them.
		vector<int> heights(maxRight - minLeft + 1, 0);
		for (const Rectangle& b : buildings)
		{
			for (int i = b.left; i <= b.right; ++i)
				heights[i - minLeft] = max(heights[i - minLeft], b.height);
		}

		// Walk the array to discover the skylne.
		Skyline result;
		int left = 0;
		// Note that we are starting from one.
		for (int i = 1; i < heights.size(); ++i)
		{
			if (heights[i] != heights[i - 1])
			{
				// Fill in the point in the skyline for the building we just finished at i - 1.
				result.emplace_back(Rectangle{ minLeft + left, minLeft + i - 1, heights[i - 1] });
				left = i;
			}
		}
		// Fill in the last building.
		result.emplace_back(Rectangle{ minLeft + left, maxRight, heights.back() });
		return result;
	}
}
