// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	typedef enum
	{
		RED,
		WHITE,
		BLUE
	} Color;

	void DutchFlagPartition(int pivot, vector<Color>& a)
	{
		Color pivotVal = a[pivot];
		/**
		* Keep the following invariants during partitioning:
		* bottom group: A[0, smaller - 1].
		* middle group: A[smaller, equal - 1].
		* unclassified group: A[equal, larger - 1].
		* top group: A[larger, A.size() - 1].
		*/
		int equalStart = 0, unpartitioned = 0, largerStart = a.size();
		// Keep iterating as long as there is an unclassified element.
		while (unpartitioned < largerStart)
		{
			// A[equal] is the incoming unclassified element.
			if (a[unpartitioned] < pivotVal)
				swap(a[equalStart++], a[unpartitioned++]);
			else if (a[unpartitioned] == pivotVal)
				++unpartitioned;
			else
				// Note how is the largerStart how is decrementing BEFORE we get the value at that index, otherwise we will access outside the vector's range.
				swap(a[unpartitioned], a[--largerStart]); // A[equal] > pivot.
		}
	}
}
