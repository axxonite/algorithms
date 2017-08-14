#include "stdafx.h"

namespace Solutions
{
	void BubbleSort(vector<int>& a)
	{
		// Outer loop: iterate every element.
		for (auto i = 0; i < a.size(); i++)
		{
			// Inner loop: iterate elements from n-1 down to i+1
			for (auto j = a.size() - 1; j > i; j--)
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
