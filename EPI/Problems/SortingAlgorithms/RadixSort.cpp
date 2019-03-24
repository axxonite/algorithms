#include "stdafx.h"

#define TEST 0

vector<int> RadixSort(vector<int> values, int maxDigits)
{
	vector<int> result(values.size());
	return result;
}

#pragma region Test

void RadixSortTest()
{
#if TEST
	vector<int> a;
	default_random_engine rnd;
	uniform_int_distribution<int> dis(0, 1000);
	for (int i = 0; i < 1000; ++i)
		a.emplace_back(dis(rnd));
	RadixSort(a, 1000);
	for (int i = 1; i < 1000; i++)
		assert(a[i] >= a[i - 1]);
#endif
}

#pragma endregion Test