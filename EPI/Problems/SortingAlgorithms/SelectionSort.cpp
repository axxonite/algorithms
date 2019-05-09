#include "stdafx.h"

// #define TEST

void SelectionSort(vector<int>& a)
{
}

#pragma region Test

void SelectionSortTest()
{
#ifdef TEST
	vector<int> a;
	default_random_engine rnd;
	const uniform_int_distribution<int> dis(0, 100000);
	a.reserve(1000);
	for (int i = 0; i < 1000; ++i)
		a.emplace_back(dis(rnd));
	SelectionSort(a);
	for (size_t i = 1; i < 1000; i++)
		assert(a[i] >= a[i - 1]);
#endif
}

#pragma endregion Test