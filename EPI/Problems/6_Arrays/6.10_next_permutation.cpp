// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

#define TEST 0

vector<int> NextPermutation(vector<int> perm)
{
	return {};
}

#pragma region Test

void NextPermutationTest()
{
#if TEST
	default_random_engine gen((random_device())());
	for (int times = 0; times < 1000; ++times)
	{
		vector<int> perm;
		uniform_int_distribution<int> dis(1, 100);
		int n = dis(gen);
		uniform_int_distribution<int> n_dis(0, n - 1);
		generate_n(back_inserter(perm), n, [&] { return n_dis(gen); });

		vector<int> ans(NextPermutation(perm));
		auto copy = perm;
		// Use built-in function verification.
		bool has_next_one = next_permutation(copy.begin(), copy.end());
		assert((ans.size() == 0 && !has_next_one) || equal(ans.cbegin(), ans.cend(), copy.cbegin(), copy.cend()));
	}
#endif
}

#pragma endregion Test
