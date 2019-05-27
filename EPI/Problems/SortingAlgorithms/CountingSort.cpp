#include "stdafx.h"

// #define TEST

void CountingSort(vector<int>& a, int maxValue)
{
}

#pragma region Test

void CountingSortTest()
{
#ifdef TEST
	vector<int> a;
	default_random_engine rnd;
	uniform_int_distribution<int> dis(0, 1000);
	for (int i = 0; i < 1000; ++i)
		a.emplace_back(dis(rnd));
	CountingSort(a, 1000);
	for (int i = 1; i < 1000; i++)
		assert(a[i] >= a[i - 1]);
#endif
}

#pragma endregion Test