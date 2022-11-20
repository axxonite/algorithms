// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	int SquareRoot(int k)
	{
		long long left = 0, right = k;
		// Candidate interval [left, right] where everything before left has square <= k, and everything after right has square > k.
		// we are looking for the lowest left that is strictly > k.
		// Note that we keep going till left is PAST right. If we don't, we will not give the right answer when k is zero.
		while (left <= right)
		{
			long long mid = left + ((right - left) / 2);
			long long midSquared = mid * mid;
			if (midSquared <= k)
				left = mid + 1; // Mid is <= k, so left starts at mid + 1
			else
				right = mid - 1; // Mid is > k, so continue search from right - 1.
		}
		return int(left - 1); // Left is > k, so left - 1 wil be <= k.
	}
}
