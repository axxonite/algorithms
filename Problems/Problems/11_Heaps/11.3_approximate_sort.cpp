// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

#define TEST 0

vector<int> SortApproximatelySortedData(istringstream* sequence, int k)
{
	vector<int> result;
	return result;
}

#pragma region Test

// It should sort to 1, 2, 3, 4, 5, 6, 7, 8, 9.
void SortApproximatelySortedDataSimpleTest()
{
	vector<int> A = {2, 1, 5, 4, 3, 9, 8, 7, 6};
	stringstream ss;
	for (int a : A)
	{
		ss << a << ' ';
	}
	istringstream sequence(ss.str());
	auto result = SortApproximatelySortedData(&sequence, 3);
	vector<int> golden_result = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	assert(equal(result.begin(), result.end(), golden_result.begin(),
		golden_result.end()));
}

void SortApproximatelySortedDataTest()
{
#if TEST
	SortApproximatelySortedDataSimpleTest();
	default_random_engine gen((random_device())());
	int n;
	uniform_int_distribution<int> n_dis(1, 10000);
	n = n_dis(gen);
	vector<int> A;
	uniform_int_distribution<int> dis(1, 999999);
	for (int i = 0; i < n; ++i)
	{
		A.push_back(dis(gen));
	}
	stringstream ss;
	for (int a : A)
	{
		ss << a << ' ';
	}
	istringstream sequence(ss.str());
	auto result = SortApproximatelySortedData(&sequence, n - 1);
	sort(A.begin(), A.end());
	assert(equal(result.begin(), result.end(), A.begin(), A.end()));
#endif
}

#pragma endregion Test
