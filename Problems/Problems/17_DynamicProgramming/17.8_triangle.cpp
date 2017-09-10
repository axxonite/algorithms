// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

#define TEST 0

int MinimumPathWeight(const vector<vector<int>>& triangle)
{
	return 0;
}

#pragma region Test

void MinimumPathWeightTest()
{
#if TEST
	vector<vector<int>> A = {{2},{3, 4},{6, 5, 7},{4, 1, 8, 3}};
	assert(11 == MinimumPathWeight(A));
#endif
}

#pragma endregion Test
