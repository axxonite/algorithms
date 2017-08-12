#include "stdafx.h"

namespace Solutions
{
	void BubbleSort(int* a, int count)
	{
		// Outer loop: iterate every element.
		for (auto i = 0; i < count; i++)
		{
			// Inner loop: iterate elements from n-1 down to i+1
			for (auto j = count - 1; j > i; j--)
			{
				if (a[j] < a[j - 1])
				{
					// Swap the contiguous elements if they're in the wrong order.
					auto temp = a[j];
					a[j] = a[j - 1];
					a[j - 1] = temp;
				}
			}
		}
	}
}