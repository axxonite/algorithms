// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"
#include "shared.h"

#define TEST 0

int MinimumMessiness(const vector<string>& words, int lineLength) 
{
	return 0;
}

#pragma region Test
void SmallTestMinimumMessiness()
{
	assert(MinimumMessiness({ "aaa", "bbb", "c", "d", "ee", "ff", "gggggg" },11) == 45);
	assert(MinimumMessiness({ "a", "b", "c", "d" }, 5) == 8);
}

void MinimumMessinessTest()
{
#if TEST
  	SmallTestMinimumMessiness();
	default_random_engine gen((random_device())());
	int n, L;
	uniform_int_distribution<int> n_dis(1, 30);
	n = n_dis(gen);
	uniform_int_distribution<int> L_dis(11, 20);
	L = L_dis(gen);
	vector<string> W;
	for (int i = 0; i < n; ++i) {
		uniform_int_distribution<int> dis(1, 10);
		W.push_back(RandString(dis(gen)));
	}
	//for (int i = 0; i < n; ++i) 
	//{
	//	cout << W[i] << ' ';
	//}
	//cout << L << endl;
	//cout << MinimumMessiness(W, L) << endl;

#endif
}
#pragma endregion Test
