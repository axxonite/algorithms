#include "stdafx.h"

// #define TEST

void BubbleSort(vector<int>& a)
{
}

#pragma region Test

void BubbleSortTest()
{
#ifdef TEST
	vector<int> a;
	default_random_engine rnd;
	uniform_int_distribution<int> dis(0, 100000);
	for (int i = 0; i < 1000; ++i)
		a.emplace_back(dis(rnd));
	BubbleSort(a);
	for (int i = 1; i < 1000; i++)
		assert(a[i] >= a[i - 1]);
#endif
}

#pragma endregion Test