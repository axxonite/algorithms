// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

#define TEST 0

// A is passed by value argument, since we change it.
int FindFirstMissingPositive(vector<int> A)
{
	return -1;
}

#pragma region Test

int FindFirstMissingPositiveCheckAns(vector<int> A)
{
	sort(A.begin(), A.end());
	int target = 1;
	for (int a : A)
	{
		if (a > 0)
		{
			if (a == target)
				++target;
			else if (a > target)
				return target;
		}
	}
	return target;
}

void FindFirstMissingPositiveTest()
{
#if TEST
	default_random_engine gen((random_device())());
	for (int times = 0; times < 1000; ++times)
	{
		size_t n;
		uniform_int_distribution<size_t> dis(0, 500000);
		n = dis(gen);
		vector<int> A;
		uniform_int_distribution<int> dis_n(0, static_cast<int>(n));
		generate_n(back_inserter(A), n, [&] { return dis_n(gen); });
		cout << "n = " << n << endl;
		/*
		copy(A.cbegin(), A.cend(), ostream_iterator<int>(cout, " "));
		cout << endl;
		cout << FindFirstMissingPositive(A) << " " << CheckAns(A) << endl;
		*/
		assert(FindFirstMissingPositive(A) == FindFirstMissingPositiveCheckAns(A));
	}
#endif
}
#pragma endregion Test
