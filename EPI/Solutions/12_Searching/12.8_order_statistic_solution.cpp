// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	// Partition A[left, right] around pivotIndex, returns the new index of the pivot, newPivotIndex, after partition. After partitioning, A[left, newPivotIndex - 1] contains elements that are greater than the pivot, and
	// A[newPivotIndex + 1, right] contains elements that are less than the pivot.
	// Note: "less than" is defined by the Compare object.
	// Returns the new index of the pivot element after partition.
	template <typename Compare>
	int PartitionAroundPivot(int left, int right, int pivotIndex, Compare comp, vector<int>& a)
	{
		int pivotVal = a[pivotIndex];
		int j = left - 1;
		swap(a[pivotIndex], a[right]);
		for (int i = left; i < right; ++i)
			if (comp(a[i], pivotVal))
				swap(a[i], a[j++]);
		swap(a[right], a[j]);
		return j;
	}

	// The numbering starts from one for k.
	template <typename Compare>
	int FindKth(int k, Compare comp, vector<int>& a)
	{
		int left = 0, right = a.size() - 1;
		default_random_engine gen((random_device())());
		while (left <= right)
		{
			// Generates a random integer in [left, right].
			int pivotIndex = uniform_int_distribution<int>{ left, right }(gen);
			int newPivotIndex = PartitionAroundPivot(left, right, pivotIndex, comp, a);
			if (newPivotIndex == k - 1)
				return a[newPivotIndex];
			if (newPivotIndex > k - 1)
				right = newPivotIndex - 1;
			else
				left = newPivotIndex + 1; // new_pivot_idx < k - 1.
		}
		throw length_error("no k-th node in array A");
	}

	int FindKthLargest(int k, vector<int>& a)
	{
		return FindKth(k, greater<int>(), a);
	}

	int FindKthSmallest(int k, vector<int>& a)
	{
		return FindKth(k, less<int>(), a);
	}
}
