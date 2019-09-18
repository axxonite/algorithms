// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

// #define TEST

void RookAttack( vector<vector<int>>& a )
{
}

#pragma region Test

void RookAttackCheckAns(const vector<vector<int>>& A, const vector<vector<int>>& ans)
{
	for (size_t i = 0; i < A.size(); ++i)
	{
		for (size_t j = 0; j < A[i].size(); ++j)
		{
			if (!A[i][j])
			{
				for (size_t k = 0; k < ans.size(); ++k)
					assert(!ans[k][j]);
				for (size_t k = 0; k < ans[i].size(); ++k)
					assert(!ans[i][k]);
			}
		}
	}
}

void RookAttackTest()
{
#ifdef TEST
	default_random_engine gen((random_device())());
	for (int times = 0; times < 100; ++times)
	{
		size_t m, n;
		uniform_int_distribution<size_t> dis(1, 50);
		m = dis(gen) , n = dis(gen);
		vector<vector<int>> A(m, vector<int>(n));
		uniform_int_distribution<int> zero_or_one(0, 1);
		for (size_t i = 0; i < m; ++i)
		{
			for (size_t j = 0; j < n; ++j)
				A[i][j] = zero_or_one(gen);
		}
		auto copy_A(A);
		cout << "m = " << m << ", n = " << n << endl;
		RookAttack(A);
		RookAttackCheckAns(copy_A, A);
	}
#endif
}

#pragma endregion Test
