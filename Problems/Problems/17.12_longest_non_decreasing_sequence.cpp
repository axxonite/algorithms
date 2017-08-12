// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"
#include <algorithm>
#include <vector>
#include <cassert>

using namespace std;

int LongestNondecreasingSubsequenceLength(const vector<int>& A) 
{
	return 0;
}

void LongestNondecreasingSubsequenceLengthTest()
{
	vector<int> a = { 0, 8, 4, 12, 2, 10, 6, 14, 1, 9 };
	assert(LongestNondecreasingSubsequenceLength(a) == 4);
}