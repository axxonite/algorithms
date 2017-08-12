// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"
#include <algorithm>
#include <cassert>
#include <vector>

using namespace std;

int MaximumRevenue(const vector<int>& coins) 
{
	return 0;
}

void ComputeMaximumRevenueForRangeTest() 
{
	vector<int> coins = { 25, 5,  10, 5,  10, 5,  10, 25, 1,  25, 1,  25, 1,  25, 5,  10 };
	assert(140 == MaximumRevenue(coins));
}
