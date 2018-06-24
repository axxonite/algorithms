#include "stdafx.h"

namespace Solutions
{
	void BubbleSort(vector<int>& a)
	{
		// Outer loop: iterate every element.
		for (auto i = 0; i < a.size(); i++)
		{
			// Inner loop: iterate elements from n-1 down to i+1 - this is at the heart of the "bubble" part of the algorithm,
			// where the minimum value in the unsorted partition will float "up" towards the beginning of the array, to finally
			// land on the top unsorted slot.
			for (auto j = a.size() - 1; j > i; j--)
			{
				// Swap the contiguous elements if they're in the wrong order.
				if (a[j] < a[j - 1])
					swap(a[j], a[j - 1]);
			}
			// Invariant: the range from a[j] to a[i] is sorted.
		}
	}
}
