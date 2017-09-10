// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

#define TEST 0

struct IndexPair
{
	int index1, index2;
};

IndexPair FindPairSumK(const vector<int>& a, int k)
{
	return {};
}

#pragma region Test

static void SimpleTest()
{
	vector<int> A = {0, 0, -1, 2, -3, -3};
	IndexPair ans = FindPairSumK(A, 2);
	assert(ans.index1 != -1);
}

void FindPairSumKTest()
{
#if TEST
	SimpleTest();
	default_random_engine gen((random_device())());
	for (int times = 0; times < 100; ++times)
	{
		int n;
		uniform_int_distribution<int> dis(1, 10000);
		n = dis(gen);
		vector<int> a;
		uniform_int_distribution<int> dis2(-10000, 10000);
		generate_n(back_inserter(a), n, [&] { return dis2(gen); });
		sort(a.begin(), a.end(), [](int x, int y) { return abs(x) < abs(y); });
		int k = dis2(gen);
		IndexPair ans = FindPairSumK(a, k);
		if (ans.index1 != -1 && ans.index2 != -1)
		{
			assert(a[ans.index1] + a[ans.index2] == k);
			//cout << a[ans.index1] << "+" << a[ans.index2] << "=" << k << endl;
		}
		else
		{
			sort(a.begin(), a.end());
			int l = 0, r = a.size() - 1;
			bool found = false;
			while (l < r)
			{
				if (a[l] + a[r] == k)
				{
					//cout << a[l] << "+" << a[r] << "=" << k << endl;
					found = true;
					break;
				}
				if (a[l] + a[r] < k)
				{
					++l;
				}
				else
				{
					--r;
				}
			}
			//cout << "no answer" << endl;
			assert(!found);
		}
	}
#endif
}

#pragma endregion Test
