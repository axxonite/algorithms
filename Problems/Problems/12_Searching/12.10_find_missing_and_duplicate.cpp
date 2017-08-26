// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

#define TEST 0

struct DuplicateAndMissing
{
	int duplicate, missing;
};

DuplicateAndMissing FindDuplicateMissing(const vector<int>& A)
{
	return DuplicateAndMissing{0, 0};
}

#pragma region Test

void FindDuplicateMissingSimpleTest()
{
	vector<int> A = {0, 1, 2, 4, 5, 6, 6};
	auto ans = FindDuplicateMissing(A);
	assert(ans.duplicate == 6 && ans.missing == 3);

	A = {0, 0, 1};
	ans = FindDuplicateMissing(A);
	assert(ans.duplicate == 0 && ans.missing == 2);

	A = {1, 3, 2, 5, 3, 4};
	ans = FindDuplicateMissing(A);
	assert(ans.duplicate == 3 && ans.missing == 0);
}

void FindDuplicateMissingTest()
{
#if TEST
	FindDuplicateMissingSimpleTest();
	default_random_engine gen((random_device())());
	for (int times = 0; times < 1000; ++times)
	{
		int n;
		uniform_int_distribution<int> n_dis(2, 10000);
		n = n_dis(gen);
		vector<int> A(n);
		iota(A.begin(), A.end(), 0);
		uniform_int_distribution<int> dis(0, n - 1);
		int missing_idx = dis(gen);
		int missing = A[missing_idx];
		int dup_idx = dis(gen);
		while (dup_idx == missing_idx)
		{
			dup_idx = dis(gen);
		}
		int dup = A[dup_idx];
		A[missing_idx] = dup;
		DuplicateAndMissing ans = FindDuplicateMissing(A);
		//cout << "times = " << times << endl;
		//cout << dup << ' ' << missing << endl;
		//cout << ans.duplicate << ' ' << ans.missing << endl;
		assert(ans.duplicate == dup && ans.missing == missing);
	}
#endif
}
#pragma endregion Test
