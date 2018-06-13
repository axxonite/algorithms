// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	// shortcut to simplify the code.
	int GetValue(const vector<int>& x, int index)
	{
		if (index < 0)
			return numeric_limits<int>::min();
		if (index >= x.size())
			return numeric_limits<int>::max();
		return x[index];
	}

	int FindKthInTwoSortedArrays(const vector<int>& a, const vector<int>& b, int k)
	{
		// the initial range is 0..a.size(), but:
		// if b has fewer than k elements, we can skip ahead to k - size(b) since the kth element will not be < than that.
		// on the right side, we don't need to search more than k elements on the right.
		int left = max(0, k - int(b.size())), right = min(int(a.size()), k);
		while (left < right)
		{
			// note that mid - 1 is the last element in the candidate set for a, k - mid - 1 is the last element in the candidate set for b
			// mid and k - mid are the elements right past the end of the candidate set, which we use to check if the elements are well ordered.
			int mid = left + ((right - left) / 2);
			if (GetValue(a, mid) < GetValue(b, k - mid - 1))
				left = mid + 1;
			else if (GetValue(a, mid - 1) > GetValue(b, k - mid))
				right = mid - 1;
			else
			{
				// take the greater of the two elements from each candidate set from a or b.
				return max(GetValue(a, mid - 1), GetValue(b, k - mid - 1));
			}
		}

		// here we have left == right. Since left - 1 is the last value in the candidate set, take the greater of the two elements between a and b as the answer.
		return max(GetValue(a, left - 1), GetValue(b, k - left - 1));
	}
}
