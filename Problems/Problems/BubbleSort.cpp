#include "stdafx.h"
#include <cassert>
#include <future>

namespace Problems
{
	void BubbleSort(int* a, int count)
	{
	}

	void BubbleSortTest()
	{
		int a[] = {3, 5, 6, 2, 4, 5, 0};
		BubbleSort(a, 7);
		int solution[] = {0, 2, 3, 4, 5, 5, 6};
		assert(memcmp(a, solution, sizeof a) == 0);
	}
}
