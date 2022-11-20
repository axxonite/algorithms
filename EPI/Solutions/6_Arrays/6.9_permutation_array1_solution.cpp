// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	void ApplyPermutation(vector<size_t>& perm, vector<int>& a)
	{
		for (int i = 0; i < a.size(); ++i)
		{
			int next = i; // Start at element i to perform the permutation cycle for this.
			// Check if the element at index i has not been moved by checking if perm[i] is nonnegative.
			while (perm[next] >= 0)
			{
				swap(a[i], a[perm[next]]); // Perform the swap.
				int temp = perm[next]; // Keep a copy a value of the next permutation index in the cycle before we modify it.
				// Subtracts perm.size() from an entry in perm to make it negative, which indicates the corresponding move has been performed.
				perm[next] -= perm.size();
				next = temp; // Move to the next value
			}
		}

		// Restore perm.
		for_each(begin(perm), end(perm), [&perm](size_t& x) { x += perm.size(); });
	}
}