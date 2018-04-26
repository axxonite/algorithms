// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	// Using the STL built-in functions obscures the fact that values in the permutation array are not necessarily distinct.
	// It's imperative that any < or > comparisons be <= or >= for the tests to validate. In practice, It seems a permutations array
	// *should* composed entirely of distinct values, otherwise, one would you differentiate between two different permutation orders?
	vector<int> NextPermutation(vector<int> perm)
	{
		// Find the first entry from the right that is smaller than the entry immediately after it.
		// Use the reverse iterator since we are looking for the last entry that is increasing.
		auto inversionPoint = is_sorted_until(perm.rbegin(), perm.rend());
		if (inversionPoint == perm.rend())
			return {}; // perm is sorted in decreasing order, so it's the last permutation.

		// Swap the entry referenced by inversion_point with smallest entry appearing after inversion_point that is greater than the entry referenced by inversion_point:
		// 1.) Find the smallest entry after inversion_point that's greater than the entry referenced by inversion_point. 
		// Since perm must be sorted in decreasing order after inversion_point, we can use a fast algorithm to find this entry.
		// upper_bound returns the first entry in the range that is greater than passed in value. Use a reverse iterator so we get the last entry in the range greater than the inversion value.
		// Since the range [inversionPoint, end] is decreasing, the first (last, since reversed) value greater than inversionPoint is the smallest possible value > inversion point value.
		auto leastUpperBound = upper_bound(perm.rbegin(), inversionPoint, *inversionPoint);

		// 2.) Perform the swap. Note that this swaps the values but the iterators point to the same location in the vector.
		iter_swap(inversionPoint, leastUpperBound);

		// Reverse the subarray that follows inversion_point.
		reverse(perm.rbegin(), inversionPoint);
		return perm;
	}
}
