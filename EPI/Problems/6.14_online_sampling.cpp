// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

#define TEST 0

// Returns a random k-sized subset of {0, 1, ..., n - 1}.
vector<int> RandomSubset(int n, int k)
{
	vector<int> result;
	return result;
}

#pragma region Test

void RandomSubsetTest()
{
#if TEST
	default_random_engine gen((random_device())());
	int n, k;
	uniform_int_distribution<int> n_dis(1, 10000);
	n = n_dis(gen);
	uniform_int_distribution<int> k_dis(1, n);
	k = k_dis(gen);
	//cout << "n = " << n << " k = " << k << endl;
	for (int i = 0; i < 100; ++i)
	{
		vector<int> res = RandomSubset(n, k);
		//cout << "result = ";
		//copy(res.begin(), res.end(), ostream_iterator<int>(cout, " "));
		//cout << endl;
	}
#endif
}

#pragma endregion Test
