// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

#define TEST 0

vector<int> GeneratePrimes(int n)
{
	return {};
}

#pragma region Test

void TestGeneratePrimes()
{
#if TEST
	default_random_engine gen((random_device())());
	for (int times = 0; times < 100; ++times)
	{
		uniform_int_distribution<int> dis(2, 1000);
		int n = dis(gen);
		cout << "n = " << n << endl;
		vector<int> primes = GeneratePrimes(n);
		for (size_t i = 0; i < primes.size(); ++i)
		{
			for (int j = 2; j < primes[i]; ++j)
			{
				assert(primes[i] % j);
			}
		}
	}
#endif
}

#pragma endregion Test
