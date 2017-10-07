// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

#define TEST 0

int GetMaxTrappedWater(const vector<int>& heights)
{
	return 0;
}

#pragma region Test

// O(n^2) checking answer.
int GetMaxTrappedWaterCheckAns(const vector<int>& heights)
{
	int res = 0;
	for (size_t i = 0; i < heights.size(); ++i)
	{
		for (size_t j = i + 1; j < heights.size(); ++j)
		{
			res = max(res, min(heights[i], heights[j]) * static_cast<int>(j - i));
		}
	}
	return res;
}

void GetMaxTrappedWaterSmallTest()
{
	vector<int> A = {1, 2, 1, 3, 4, 4, 5, 6, 2, 1, 3, 1, 3, 2, 1, 2, 4, 1};
	assert(48 == GetMaxTrappedWater(A));
	vector<int> A2 = { 1, 1 };
	assert(1 == GetMaxTrappedWater(A2));
}

void GetMaxTrappedWaterTest()
{
#if TEST
	GetMaxTrappedWaterSmallTest();
	default_random_engine gen((random_device())());
	for (int times = 0; times < 10; ++times)
	{
		size_t n;
		uniform_int_distribution<size_t> dis(2, 1000);
		n = dis(gen);
		uniform_int_distribution<int> dis_1000(1, 100);
		vector<int> heights;
		generate_n(back_inserter(heights), n, [&] { return dis_1000(gen); });
		cout << GetMaxTrappedWater(heights) << endl;
		assert(GetMaxTrappedWater(heights) == GetMaxTrappedWaterCheckAns(heights));
	}
#endif
}

#pragma endregion Test
