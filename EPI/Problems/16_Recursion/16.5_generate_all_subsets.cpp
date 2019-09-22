// Copyright (c) 2013 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

// #define TEST

vector<vector<int>> Combinations(int n, int k)
{
	vector<vector<int>> result;
	return result;
}

#pragma region Test

void SmallTestCombinations()
{
	auto result = Combinations(4, 2);
	vector<vector<int>> golden_result = {{1, 2},{1, 3},{1, 4},
		{2, 3},{2, 4},{3, 4}};
	assert(equal(result.begin(), result.end(), golden_result.begin(),
		golden_result.end()));
}

void CombinationsTest()
{
#ifdef TEST
	SmallTestCombinations();
	default_random_engine gen((random_device())());
	int n, k;
	uniform_int_distribution<int> n_dis(1, 10);
	n = n_dis(gen);
	uniform_int_distribution<int> k_dis(0, n);
	k = k_dis(gen);
	auto result = Combinations(n, k);
	cout << "n = " << n << ", k = " << k << endl;
	for (const vector<int>& vec : result) {
		for (int a : vec) {
			cout << a << " ";
		}
		cout << endl;
	}
#endif
}

#pragma endregion Test
