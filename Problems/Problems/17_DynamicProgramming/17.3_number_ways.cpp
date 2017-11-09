// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

#define TEST 0

int NumberOfWays(int n, int m)
{
	return 0;
}

#pragma region Test

int ComputeNumberOfWaysSpaceEfficient(int n, int m)
{
	if (n < m)
	{
		swap(n, m);
	}
	vector<int> A(m, 1);
	for (int i = 1; i < n; ++i)
	{
		int prev_res = 0;
		if (n < m)
		{
			swap(n, m);
		}
		for (int j = 0; j < m; ++j)
		{
			A[j] = A[j] + prev_res;
			prev_res = A[j];
		}
	}
	return A[m - 1];
}

int NumberOfWaysCheckAns(int n, int k)
{
	vector<vector<int>> table(n + 1, vector<int>(k + 1));
	// Basic case: C(i, 0) = 1.
	for (int i = 0; i <= n; ++i)
	{
		table[i][0] = 1;
	}
	// Basic case: C(i, i) = 1.
	for (int i = 1; i <= k; ++i)
	{
		table[i][i] = 1;
	}
	// C(i, j) = C(i - 1, j) + C(i - 1, j - 1).
	for (int i = 2; i <= n; ++i)
	{
		for (int j = 1; j < i && j <= k; ++j)
		{
			table[i][j] = table[i - 1][j] + table[i - 1][j - 1];
		}
	}
	return table[n][k];
}

void NumberOfWaysTest()
{
#if TEST
	default_random_engine gen((random_device())());
	for (int times = 0; times < 1000; ++times)
	{
		int n, m;
		uniform_int_distribution<int> dis(1, 10);
		n = dis(gen);
		m = dis(gen);
		cout << "n = " << n << ", m = " << m
			<< ", number of ways = " << NumberOfWays(n, m) << endl;
		assert(NumberOfWaysCheckAns(n + m - 2, m - 1) == NumberOfWays(n, m));
		assert(ComputeNumberOfWaysSpaceEfficient(n, m) == NumberOfWays(n, m));
	}
#endif
}

#pragma endregion Test
