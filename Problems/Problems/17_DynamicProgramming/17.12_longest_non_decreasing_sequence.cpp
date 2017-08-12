// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

#define TEST 0

int LongestNondecreasingSubsequenceLength(const vector<int>& A)
{
	return 0;
}

#pragma region Test

void LongestNondecreasingSubsequenceLengthTest()
{
#if TEST
	vector<int> a = { 0, 8, 4, 12, 2, 10, 6, 14, 1, 9 };
	assert(LongestNondecreasingSubsequenceLength(a) == 4);
#endif
}

#pragma endregion Test
