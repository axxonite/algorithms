#include "stdafx.h"

namespace Solutions
{
	// --------------------------------------------------
	// Quicksort - pick a key value, classify with respect to the key values as < or >, then run again on each < and > classification. O(n lg n)
	int Partition(vector<int>& values, int a, int b)
	{
		// Note how the insertion point j is right before our range, so that when we do insert an element, we will increment it to the first element in the range.
		int j = a - 1;
		for (int i = a; i < b; i++)
		{
			// Using <=, and not <, is crucial here. This is because you can end up with a range of only two equal values, in which case no swap will happen, and the returned
			// pivot will be the zero index. Since in the Quicksort call from [p..end] we are iterating over the same range we just iterated, and we have made no modifications
			// to the array, we end up redoing the same work in an infinite loop.
			if (values[i] <= values[b])
			{
				// Swap i with insertion point so i is in the left section
				swap(values[i], values[++j]);
			}
		}
		// Notice how we swap the final value (the pivot) at the insertion point.
		swap(values[++j], values[b]);
		return j; // This is where the key value ended up at.
	}

	void Quicksort(vector<int>& values, int start, int end)
	{
		if (start < end)
		{
			auto p = Partition(values, start, end);
			// the correct thing to do is here to split the sort with p-1 as the last element. If the range from start to end is already in sorted, the returned pivot will be p = end. Calling quicksort(start, p) on this would result in an infinite loop.
			Quicksort(values, start, p - 1);
			Quicksort(values, p, end);
		}
	}

	void Quicksort(vector<int>& values)
	{
		Quicksort(values, 0, int(values.size() - 1));
	}
}
