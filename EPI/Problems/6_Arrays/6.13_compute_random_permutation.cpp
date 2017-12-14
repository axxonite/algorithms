// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"
#include "Solutions/6_Arrays/6.11_offline_sampling_solution.h"

#define TEST 0

vector<int> ComputeRandomPermutation(int n)
{
	vector<int> permutation(n);
	return permutation;
}

#pragma region Test

void ComputeRandomPermutationTest()
{
#if TEST
	default_random_engine gen((random_device())());
	uniform_int_distribution<int> n_dis(1, 1000000);
	int n = n_dis(gen);
	cout << n << endl;
	auto result = ComputeRandomPermutation(n);
	sort(result.begin(), result.end());
	for (int i = 0; i < n; ++i)
	{
		assert(result[i] == i);
	}
#endif
}

#pragma endregion Test
