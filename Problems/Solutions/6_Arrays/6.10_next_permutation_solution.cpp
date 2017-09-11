// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	vector<int> NextPermutation(vector<int> perm)
	{
		// Find the first entry from the right that is smaller than the entry immediately after it.
		auto inversionPoint = is_sorted_until(perm.rbegin(), perm.rend());
		if (inversionPoint == perm.rend())
			return {}; // perm is sorted in decreasing order, so it's the last permutation.

		// Swap the entry referenced by inversion_point with smallest entry appearing after inversion_point that is greater than the entry referenced by inversion_point:
		// 1.) Find the smallest entry after inversion_point that's greater than the entry referenced by inversion_point. Since perm must be sorted in decreasing order after inversion_point, we can use a fast algorithm to find this entry.
		auto leastUpperBound = upper_bound(perm.rbegin(), inversionPoint, *inversionPoint);

		// 2.) Perform the swap. Note that this swaps the values but the iterators point to the same location in the vector.
		iter_swap(inversionPoint, leastUpperBound);

		// Reverse the subarray that follows inversion_point.
		reverse(perm.rbegin(), inversionPoint);
		return perm;
	}
}
