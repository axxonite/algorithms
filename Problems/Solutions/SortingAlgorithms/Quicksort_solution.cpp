#include "stdafx.h"

namespace Solutions
{
	// --------------------------------------------------
	// Quicksort - pick a key value, classify with respect to the key values as < or >, then run again on each < and > classication. O(n lg n)
	int Partition(vector<int>& values, int a, int b)
	{
		// Note how the insertion point j is right before our range, so that when we do insert an element, we will increment it to the first element in the range.
		int j = a - 1;
		for (int i = a; i < b; i++)
		{
			if (values[i] <= values[b])
			{
				// Swap i with insertion point so i is in the left section
				j++;
				swap(values[i], values[j]);
			}
		}
		// Notice how we swap the final value (the pivot) at the insertion point.
		swap(values[j + 1], values[b]);
		return j + 1; // This is where the key value ended up at.
	}

	void Quicksort(vector<int>& values, int start, int end)
	{
		if (start < end)
		{
			auto p = Partition(values, start, end);
			Quicksort(values, start, p - 1);
			Quicksort(values, p, end);
		}
	}

	void Quicksort(vector<int>& values)
	{
		Quicksort(values, 0, int(values.size() - 1));
	}
}
