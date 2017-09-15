// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

#define TEST 0

vector<vector<int>> GeneratePowerSet(const vector<int>& inputSet)
{
	vector<vector<int>> powerSet;
	return powerSet;
}

#pragma region Test
void GeneratePowerSetSimpleTest()
{
	vector<vector<int>> golden_result = {{0, 1, 2},{0, 1},{0, 2},{0},
		{1, 2},{1},{2},{}};
	auto result = GeneratePowerSet({0, 1, 2});
	assert(equal(result.begin(), result.end(), golden_result.begin(),
		golden_result.end()));
}

void GeneratePowerSetTest()
{
#if TEST
	GeneratePowerSetSimpleTest();
	vector<int> S;
	default_random_engine gen((random_device())());
	uniform_int_distribution<int> dis(1, 10);
	S.resize(dis(gen));
	iota(S.begin(), S.end(), 0);
	auto power_set = GeneratePowerSet(S);
	for (const vector<int>& one_set : power_set)
	{
		copy(one_set.begin(), one_set.end(), ostream_iterator<int>(cout, " "));
		cout << endl;
	}
#endif
}

#pragma endregion Test
