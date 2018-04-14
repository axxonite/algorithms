// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"
#include "2_sum_solution.h"

namespace Solutions
{
	// this is kind of buggy.
	// for example, say t = 3.
	// then a = {1, 1} will return true because t-a=2 and the array contains two 1s that add to two. So we are using two entries, not three. 
	// This would be ok if the directive is that it's ok to reuse each entry.
	// However, a = {1} will return false because t-a=2 again but the array doesn't contain a two-sum that would add up to 2. So, the algorithm arbitrarily allows an entry to be reused twice, but not three times.
	bool HasThreeSum(vector<int> A, int t)
	{
		sort(A.begin(), A.end());
		// Finds if the sum of two numbers in A equals to t - a.
		return any_of(begin(A), end(A), [&](int a) { return Solutions::HasTwoSum(A, t - a); });
	}
}
