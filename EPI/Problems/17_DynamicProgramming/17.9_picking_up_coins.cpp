// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

#define TEST 0

int MaximumRevenue(const vector<int>& coins)
{
	return 0;
}

#pragma region Test

void ComputeMaximumRevenueForRangeTest()
{
#if TEST
	vector<int> coins = { 25, 5,  10, 5,  10, 5,  10, 25, 1,  25, 1,  25, 1,  25, 5,  10 };
	assert(140 == MaximumRevenue(coins));
#endif
}

#pragma endregion
