// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

// #define TEST

int LongestNondecreasingSubsequenceLength(const vector<int>& a)
{
  return 0;
}

#pragma region Test

void LongestNondecreasingSubsequenceLengthTest()
{
#ifdef TEST
	vector<int> a = { 0, 8, 4, 12, 2, 10, 6, 14, 1, 9 };
	assert(LongestNondecreasingSubsequenceLength(a) == 4);
	vector<int> a2 = { 0, 8, 4, 12, 12, 12, 12, 12, 2, 10, 6, 14, 1, 9 };
	assert(LongestNondecreasingSubsequenceLength(a2) == 8);
#endif
}

#pragma endregion Test
