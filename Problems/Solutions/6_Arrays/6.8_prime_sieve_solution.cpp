// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	vector<int> GeneratePrimes(int n)
	{
		// We start the sieve at 3.
		const int size =(n - 3)/ 2 + 1;
		vector<int> primes;
		primes.emplace_back(2); // We know a priori that 2 is prime.
		// is_prime[i] represents whether (2i + 3) is prime or not. Initially, set each to true. Then use sieving to eliminate nonprimes.
		deque<bool> isPrime(size, true);
		for (int i = 0; i < size; ++i)
		{
			if (isPrime[i])
			{
				int p = i * 2 + 3;
				primes.emplace_back(p);
				// IMPORTANT: All numbers of the form ki where k < i have already been sieved out, so start the sieve at i^2, hence
				// Start sieve from p^2.
				// The algebraic equation below is equivalent to taking the index, converting it to the corresponding prime with 2i + 3, squaring it
				// then converting back to an index with (i-3)/2.
				// Note that we need to use long for j because p^2 might overflow.
				for (long long j = long long(i) * long long(i) * 2 + 6 * i + 3; j < size; j += p)
					isPrime[j] = false;
			}
		}
		return primes;
	}
}
