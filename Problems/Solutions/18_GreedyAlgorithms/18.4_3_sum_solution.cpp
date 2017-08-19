// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"
#include "2_sum_solution.h"

namespace Solutions
{
	bool HasThreeSum(vector<int> A, int t)
	{
		sort(A.begin(), A.end());
		// Finds if the sum of two numbers in A equals to t - a.
		return any_of(begin(A), end(A), [&](int a) { return Solutions::HasTwoSum(A, t - a); });
	}
}
