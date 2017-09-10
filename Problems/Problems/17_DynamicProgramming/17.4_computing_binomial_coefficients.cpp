// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

#define TEST 0

int ComputeBinomialCoefficient(int n, int k)
{
	return 0;
}

#pragma region Test

int ComputeBinomialCoefficientsSpaceEfficient(int n, int k)
{
	k = min(k, n - k);
	vector<int> table(k + 1, 0);
	table[0] = 1; // C(0, 0).
	// C(i, j) = C(i - 1, j) + C(i - 1, j - 1).
	for (int i = 1; i <= n; ++i)
	{
		for (int j = min(i, k); j >= 1; --j)
		{
			table[j] = table[j] + table[j - 1];
		}
	}
	return table[k];
}

int CheckAns(int n, int k)
{
	vector<int> number;
	for (int i = 0; i < k; ++i)
	{
		number.emplace_back(n - i);
	}

	vector<int> temp;
	for (int i = 2; i <= k; ++i)
	{
		bool find = false;
		for (int& a : number)
		{
			if ((a % i) == 0)
			{
				a /= i;
				find = true;
				break;
			}
		}
		if (find == false)
		{
			temp.emplace_back(i);
		}
	}

	int res = 1;
	for (int a : number)
	{
		res *= a;
	}

	for (int a : temp)
	{
		res /= a;
	}

	return res;
}

void ComputeBinomialCoefficientTest()
{
#if TEST
	default_random_engine gen((random_device())());
	for (int times = 0; times < 1000; ++times)
	{
		int n, k;
		uniform_int_distribution<int> n_dis(1, 21);
		n = n_dis(gen);
		uniform_int_distribution<int> k_dis(0, n);
		k = k_dis(gen);

		int res = ComputeBinomialCoefficient(n, k);
		cout << "res = " << res << endl;
		assert(res == CheckAns(n, k));
		assert(res == ComputeBinomialCoefficientsSpaceEfficient(n, k));
		cout << n << " out of " << k << " = " << res << endl;
	}
#endif
}

#pragma endregion Test
