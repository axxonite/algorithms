// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

// #define TEST

int CountInversions(vector<int> a)
{
  return 0;
}

#pragma region Test

// O(n^2) check of inversions.
template <typename T>
int N2Check(const vector<T>& A)
{
	int count = 0;
	for (size_t i = 0; i < A.size(); ++i)
	{
		for (size_t j = i + 1; j < A.size(); ++j)
		{
			if (A[i] > A[j])
			{
				++count;
			}
		}
	}
	cout << count << endl;
	return count;
}

void CountInversionsTest()
{
#ifdef TEST
	default_random_engine gen((random_device())());
	for (int times = 0; times < 1000; ++times)
	{
		int n;
		uniform_int_distribution<int> dis(1, 100);
		n = dis(gen);
		vector<int> A;
		for (size_t i = 0; i < n; ++i)
		{
			uniform_int_distribution<int> dis(-1000000, 1000000);
			A.emplace_back(dis(gen));
		}
		assert(N2Check(A) == CountInversions(A));
	}
#endif
}

#pragma endregion Test
