// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

// #define TEST

struct Subarray
{
	int start = 0, end = 0;
};

Subarray FindLongestIncreasingSubarray(const vector<int>& a)
{
	Subarray result = { 0, 0 };
  return result;
}

#pragma region Test

void FindLongestIncreasingSubarraySimpleTest()
{
	auto result = FindLongestIncreasingSubarray({-1, -1});
	assert(result.start == 0 && result.end == 0);
	result = FindLongestIncreasingSubarray({1, 2});
	assert(result.start == 0 && result.end == 1);
}

void FindLongestIncreasingSubarrayTest()
{
#ifdef TEST
	FindLongestIncreasingSubarraySimpleTest();
	default_random_engine gen((random_device())());
	for (int times = 0; times < 20; ++times)
	{
		vector<int> A;

		int n;
		uniform_int_distribution<int> dis(1, 1000000);
		n = dis(gen);
		uniform_int_distribution<int> pos_or_neg(0, 1);
		uniform_int_distribution<int> dis2(0, n - 1);
		for (int i = 0; i < n; ++i)
			A.emplace_back((pos_or_neg(gen) ? -1 : 1) * dis2(gen));
		Subarray result = FindLongestIncreasingSubarray(A);
		cout << result.start << ' ' << result.end << endl;
		int len = 1;
		for (int i = 1; i < A.size(); ++i)
		{
			if (A[i] > A[i - 1])
				++len;
			else
				len = 1;
			assert(len <= result.end - result.start + 1);
		}
	}
#endif
}

#pragma endregion Test
