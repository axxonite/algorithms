// Copyright (c) 2013 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

#define TEST 0

void DirectedPermutations(vector<int>& a, int offset, vector<vector<int>>& result)
{
}

vector<vector<int>> Permutations(vector<int> a)
{
	vector<vector<int>> result;
	return result;
}

#pragma region Test

void PermutationsSmallTest()
{
	vector<int> A = {0, 1, 2};
	auto result = Permutations(A);
	assert(result.size() == 6);
	vector<vector<int>> golden_result = {{0, 1, 2},{0, 2, 1},{1, 0, 2},
		{1, 2, 0},{2, 1, 0},{2, 0, 1}};
	for (int i = 0; i < 6; ++i)
	{
		assert(equal(result[i].begin(), result[i].end(), golden_result[i].begin(),
			golden_result[i].end()));
	}
}

void PermutationsTest()
{
#if TEST
	PermutationsSmallTest();
	default_random_engine gen((random_device())());
	int n;
	uniform_int_distribution<int> dis(1, 7);
	n = dis(gen);
	vector<int> A(n);
	iota(A.begin(), A.end(), 0);
	auto result = Permutations(A);
	//cout << "n = " << n << endl;
	//for (const auto& vec : result)
	//{
	//	for (int a : vec)
	//	{
	//		cout << a << " ";
	//	}
	//	cout << endl;
	//}
#endif
}
#pragma endregion Test
