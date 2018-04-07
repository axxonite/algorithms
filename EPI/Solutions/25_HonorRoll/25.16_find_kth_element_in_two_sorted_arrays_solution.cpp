// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	int FindKthInTwoSortedArrays(const vector<int>& a, const vector<int>& b, int k)
	{
		if (a.size() + b.size() < k)
			return -1; // There aren't k elements in both combined arrays.

		// start with a range of 0..k.
		// We must have k - mid < b.size() => mid > k - b.size() - 1
		// k = 6, a = 10, b = 5, 6 - 5 = 1
		int left = max(0, k - int(b.size())), right = min(int(a.size()), k); // how many elements from a that we want.
		while (left <= right)
		{
			int mid = (left + right) / 2;
			// mid is how many elements from a that we want.
			// Say k = 6, we want 4 elements in a and 2 elements in b. That means range is 0..3 for a and 0..1 for b.
			// So range for a is 0..mid-1, and range for b is 0..k-mid-1
			// We want to check that a[mid]>b[k-mid-1] and b[k-mid]>a[mid-1].
			if (mid < a.size() && a[mid] < b[k - mid - 1]) // there's a smaller element in a, we need more elements from a.
				left = mid + 1;
			else if (mid > 0 && a[mid - 1] > b[k - mid]) // there's a smaller element in b, we need more elements from b.
				right = mid - 1;
			else
			// We have a well-ordered set when we split the arrays at these points. Return the highest value between the two arrays as the kth element.
				return (mid > 0 && a[mid - 1] > b[k - mid - 1]) ? a[mid - 1] : b[k - mid - 1];
		}
		return -1;
	}
}
