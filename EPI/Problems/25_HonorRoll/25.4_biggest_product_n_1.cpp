// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

#define TEST 0

int FindBiggestNMinusOneProduct(const vector<int>& a)
{
	return -1;
}

#pragma region Test

// n^2 checking.
int FindBiggestNMinusOneProductCheckAns(const vector<int>& A)
{
	int max_product = numeric_limits<int>::min();
	for (int i = 0; i < A.size(); ++i)
	{
		int product = 1;
		for (int j = 0; j < i; ++j)
			product *= A[j];
		for (int j = i + 1; j < A.size(); ++j)
			product *= A[j];
		if (product > max_product)
			max_product = product;
	}
	return max_product;
}

void FindBiggestNMinusOneProductTest()
{
#if TEST
	default_random_engine gen((random_device())());
	for (int times = 0; times < 200; ++times)
	{
		int n;
		vector<int> A;
		uniform_int_distribution<int> dis(2, 11);
		n = dis(gen);
		for (size_t i = 0; i < n; ++i)
		{
			uniform_int_distribution<int> dis(-9, 9);
			A.emplace_back(dis(gen));
		}
		int res = FindBiggestNMinusOneProduct(A);
		assert(res == FindBiggestNMinusOneProductCheckAns(A));
	}
#endif
}

#pragma endregion Test
