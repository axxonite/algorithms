// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	int SquareRoot(int k)
	{
		int left = 0, right = k;
		// Candidate interval [left, right] where everything before left has square <= k, and everything after right has square > k.
		while (left <= right)
		{
			long long mid = left + ((right - left) / 2);
			long long mid_squared = mid * mid;
			if (mid_squared <= k)
				left = mid + 1;
			else
				right = mid - 1;
		}
		return left - 1;
	}
}
