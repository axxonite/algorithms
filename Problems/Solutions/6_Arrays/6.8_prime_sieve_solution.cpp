// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	vector<int> GeneratePrimes(int n)
	{
		const int size = floor(0.5 * (n - 3)) + 1;
		vector<int> primes;
		primes.emplace_back(2);
		// is_prime[i] represents whether (2i + 3) is prime or not. Initially, set each to true. Then use sieving to eliminate nonprimes.
		deque<bool> isPrime(size, true);
		for (int i = 0; i < size; ++i)
		{
			if (isPrime[i])
			{
				int p = (i * 2) + 3;
				primes.emplace_back(p);
				// Sieving from p^2, whose value is (4i^2 + 12i + 9). The index in is_prime is (2i^2 + 6i + 3) because is_prime[i] represents 2i + 3. Note that we need to use long for j because p^2 might overflow.
				for (long j = ((static_cast<long>(i) * static_cast<long>(i)) * 2) + 6 * i + 3; j < size; j += p)
					isPrime[j] = false;
			}
		}
		return primes;
	}
}
