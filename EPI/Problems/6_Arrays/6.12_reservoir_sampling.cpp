// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

// #define TEST

// maintain a uniform random subset of size k of the read packets.
vector<int> OnlineRandomSample(istringstream* sin, int k)
{
	vector<int> runningSample;
	return runningSample;
}

#pragma region Test

void OnlineRandomSampleTest()
{
#ifdef TEST
	int n, k;
	default_random_engine gen((random_device())());
	uniform_int_distribution<int> n_dis(0, 99999);
	n = n_dis(gen);
	uniform_int_distribution<int> k_dis(1, n);
	k = k_dis(gen);
	vector<int> A(n);
	iota(A.begin(), A.end(), 0);
	string s;
	for (int i = 0; i < A.size(); ++i)
	{
		stringstream ss;
		ss << A[i];
		s += ss.str();
		s += ' ';
	}
	cout << n << ' ' << k << endl;
	istringstream sin(s);
	vector<int> ans = OnlineRandomSample(&sin, k);
	assert(ans.size() == k);
#endif
}

#pragma endregion Test
