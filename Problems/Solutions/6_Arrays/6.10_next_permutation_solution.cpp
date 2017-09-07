// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	vector<int> NextPermutation(vector<int> perm)
	{
		// Find the first entry from the right that is smaller than the entry immediately after it.
		auto inversion_point = is_sorted_until(perm.rbegin(), perm.rend());
		if (inversion_point == perm.rend())
			return {}; // perm is sorted in decreasing order, so it's the last permutation.

		// Swap the entry referenced by inversion_point with smallest entry appearing after inversion_point that is greater than the entry referenced by inversion_point:
		// 1.) Find the smallest entry after inversion_point that's greater than the entry referenced by inversion_point. Since perm must be sorted in decreasing order after inversion_point, we can use a fast algorithm to find this entry.
		auto least_upper_bound = upper_bound(perm.rbegin(), inversion_point, *inversion_point);

		// 2.) Perform the swap.
		iter_swap(inversion_point, least_upper_bound);

		// Reverse the subarray that follows inversion_point.
		reverse(perm.rbegin(), inversion_point);
		return perm;
	}
}
