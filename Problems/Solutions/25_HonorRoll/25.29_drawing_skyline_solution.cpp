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
