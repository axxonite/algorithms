// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

#define TEST 0

int CalculateLargestRectangle(const vector<int>& heights) 
{
	return 0;
}

#pragma region Test

void CalculateLargestRectangleTest()
{
#if TEST
	vector<int> heights = { 1, 4, 2, 5, 6, 3, 2, 6, 6, 5, 2, 1, 3 };
	assert(CalculateLargestRectangle(heights) == 20);
	vector<int> heights2 = { 1, 4, 2, 5, 6, 3, 2, 6, 6, 5, 2 };
	assert(CalculateLargestRectangle(heights2) == 20);
#endif
}

#pragma endregion Test