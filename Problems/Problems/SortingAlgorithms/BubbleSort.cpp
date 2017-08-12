#include "stdafx.h"

#define TEST 0

void BubbleSort(int* a, int count)
{
}

#pragma region Test

void BubbleSortTest()
{
#if TEST
	int a[] = {3, 5, 6, 2, 4, 5, 0};
	BubbleSort(a, 7);
	int solution[] = {0, 2, 3, 4, 5, 5, 6};
	assert(memcmp(a, solution, sizeof a) == 0);
#endif
}

#pragma endregion Test
