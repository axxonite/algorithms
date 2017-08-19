// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"
#include "2_sum.h"

#define TEST 0

bool HasThreeSum(vector<int> A, int t)
{
	return false;
}

#pragma region Test

// n^3 solution.
bool CheckAns(const vector<int>& A, int t)
{
	for (int i = 0; i < A.size(); ++i)
	{
		for (int j = 0; j < A.size(); ++j)
		{
			for (int k = 0; k < A.size(); ++k)
			{
				if (A[i] + A[j] + A[k] == t)
					return true;
			}
		}
	}
	return false;
}

void HasThreeSumTest()
{
#if TEST
	default_random_engine gen((random_device())());
	for (int times = 0; times < 10; ++times)
	{
		int n, T;
		uniform_int_distribution<int> dis(1, 10000);
		n = dis(gen);
		uniform_int_distribution<int> T_dis(0, n - 1);
		T = T_dis(gen);
		vector<int> A;
		for (size_t i = 0; i < n; ++i)
		{
			uniform_int_distribution<int> dis(-100000, 100000);
			A.emplace_back(dis(gen));
		}
		assert(CheckAns(A, T) == HasThreeSum(A, T));
	}
#endif
}
#pragma endregion Test
