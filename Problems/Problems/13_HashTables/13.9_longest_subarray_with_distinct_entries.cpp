// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

#define TEST 0

int LongestSubarrayWithDistinctEntries(const vector<int>& a)
{
	return 0;
}

#pragma region Test

int LongestSubarrayWithDistinctEntriesTestCheckAns(const vector<int>& A)
{
	size_t len = 0;
	for (size_t i = 0; i < A.size(); ++i)
	{
		unordered_set<int> table;
		size_t j;
		for (j = i; A.size() - i > len && j < A.size(); ++j)
		{
			if (!table.emplace(A[j]).second)
			{
				break;
			}
		}
		len = max(len, j - i);
	}
	return len;
}

void LongestSubarrayWithDistinctEntriesTestSimpleTest()
{
	assert(1 == LongestSubarrayWithDistinctEntries({ 1, 1, 1 }));
	assert(2 == LongestSubarrayWithDistinctEntries({ 1, 2, 1 }));
	assert(3 == LongestSubarrayWithDistinctEntries({ 1, 2, 1, 3, 1, 2, 1 }));
	assert(2 ==
		LongestSubarrayWithDistinctEntries({ 1, 2, 2, 3, 3, 1, 1, 2, 1 }));
}

void LongestSubarrayWithDistinctEntriesTest()
{
#if TEST
	LongestSubarrayWithDistinctEntriesTestSimpleTest();
	default_random_engine gen((random_device())());
	uniform_int_distribution<size_t> dis(0, 1000);
	int n = dis(gen);
	cout << "n = " << n << endl;
	for (int times = 0; times < 20; ++times)
	{
		vector<int> A;
		generate_n(back_inserter(A), n, [&] { return dis(gen); });
		/*
		for (int a : a) {
		cout << a << " ";
		}
		cout << endl;
		*/
		int ans = LongestSubarrayWithDistinctEntries(A);
		int golden_ans = LongestSubarrayWithDistinctEntriesTestCheckAns(A);
		cout << ans << " " << golden_ans << endl;
		assert(ans == golden_ans);
	}
#endif
}

#pragma endregion Test
