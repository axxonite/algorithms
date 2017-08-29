// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

#define TEST 0

int FindClosestElementsInSortedArrays(const vector<vector<int>>& sorted_arrays)
{
	return 0;
}

#pragma region Test

int Distance(const vector<vector<int>>& sorted_arrays,
             const vector<int>& idx)
{
	int max_val = numeric_limits<int>::min(), min_val = numeric_limits<int>::max();
	for (int i = 0; i < idx.size(); ++i)
	{
		max_val = max(max_val, sorted_arrays[i][idx[i]]);
		min_val = min(min_val, sorted_arrays[i][idx[i]]);
	}
	return max_val - min_val;
}

void RecGenAnswer(const vector<vector<int>>& sorted_arrays, vector<int>& idx,
                  int level, int* ans)
{
	if (level == sorted_arrays.size())
	{
		*ans = min(Distance(sorted_arrays, idx), *ans);
		return;
	}
	for (int i = 0; i < sorted_arrays[level].size(); ++i)
	{
		idx[level] = i;
		RecGenAnswer(sorted_arrays, idx, level + 1, ans);
	}
}

int BruteForceGenAnswer(const vector<vector<int>>& sorted_arrays)
{
	int ans = numeric_limits<int>::max();
	vector<int> idx(sorted_arrays.size());
	RecGenAnswer(sorted_arrays, idx, 0, &ans);
	//cout << ans << endl;
	return ans;
}

void FindClosestElementsInSortedArraysTest()
{
#if TEST
	default_random_engine gen((random_device())());
	for (int times = 0; times < 10; ++times)
	{
		int n;
		vector<vector<int>> sorted_arrays;
		uniform_int_distribution<int> dis(1, 5);
		n = dis(gen);
		sorted_arrays.resize(n);
		for (int i = 0; i < n; ++i)
		{
			uniform_int_distribution<int> dis(1, 20);
			int size = dis(gen);
			for (int j = 0; j < size; ++j)
			{
				uniform_int_distribution<int> dis(0, 9999);
				sorted_arrays[i].emplace_back(dis(gen));
			}
			sort(sorted_arrays[i].begin(), sorted_arrays[i].end());
		}
		int ans = FindClosestElementsInSortedArrays(sorted_arrays);
		//cout << ans << endl;
		assert(BruteForceGenAnswer(sorted_arrays) == ans);
	}
#endif
}

#pragma endregion Test
