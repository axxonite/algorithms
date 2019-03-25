#include "stdafx.h"

#define TEST 1

void InsertionSort(vector<int>& a)
{
  for (int i = 1; i < a.size(); ++i)
  {
    for (int j = i - 1; j >= 0; --j)
      if (a[j] > a[j + 1])
        swap(a[j], a[j + 1]);
      else break;
  }
}

#pragma region Test

void InsertionSortTest()
{
#if TEST
	vector<int> a;
	default_random_engine rnd;
	uniform_int_distribution<int> dis(0, 100000);
	for (int i = 0; i < 1000; ++i)
		a.emplace_back(dis(rnd));
	InsertionSort(a);
	for (int i = 1; i < 1000; i++)
		assert(a[i] >= a[i - 1]);
#endif
}

#pragma endregion Test