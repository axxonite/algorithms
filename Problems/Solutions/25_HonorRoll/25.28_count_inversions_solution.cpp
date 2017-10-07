// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	// Merge two sorted subarrays a[start, mid - 1] and a[mid, end - 1] into a[start, end - 1] and return the number of inversions across a[start, mid -1] and a[mid, end - 1].
	int MergeSortAndCountInversionsAcrossSubarrays(int start, int mid, int end, vector<int>& a)
	{
		vector<int> sortedA;
		int leftStart = start, rightStart = mid, inversionCount = 0;

		while (leftStart < mid && rightStart < end)
		{
			if (a[leftStart] <= a[rightStart])
				sortedA.emplace_back(a[leftStart++]); // left side is < right side, add to sorted A, no inversions.
			else
			{
				// a[leftStart, mid - 1] are the inversions of a[right_start].
				inversionCount += mid - leftStart; // left side is > right side, so everything after the left side is inverted with that value on the right side
				sortedA.emplace_back(a[rightStart++]);
			}
		}

		// One of the sides is finished, copy the remaining elements for the other side.
		copy(a.begin() + leftStart, a.begin() + mid, back_inserter(sortedA));
		copy(a.begin() + rightStart, a.begin() + end, back_inserter(sortedA));

		// Updates a with sortedA.
		// IMPORTANT - Don't forget to copy the destination at the start offset.
		copy(sortedA.begin(), sortedA.end(), a.begin() + start);
		return inversionCount;
	}

	// Return the number of inversions in a[start, end - 1].
	int CountSubarrayInversions(int start, int end, vector<int>& a)
	{
		if (end - start <= 1)
			return 0;

		int mid = start + (end - start) / 2;
		// Count the inversions within each half, and the inversions accross the halves.
		return CountSubarrayInversions(start, mid, a) + CountSubarrayInversions(mid, end, a) + MergeSortAndCountInversionsAcrossSubarrays(start, mid, end, a);
	}

	int CountInversions(vector<int> a)
	{
		// We use a.size() as the right bound since the right bound is considered to be one past the last element that will be processed.
		return CountSubarrayInversions(0, a.size(), a);
	}
}