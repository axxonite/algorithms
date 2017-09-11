// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	void ApplyPermutation(vector<int>& perm, vector<int>& a)
	{
		for (int i = 0; i < a.size(); ++i)
		{
			int next = i;
			// Check if the element at index i has not been moved by checking if perm[i] is nonnegative.
			while (perm[next] >= 0)
			{
				swap(a[i], a[perm[next]]);
				int temp = perm[next];
				// Subtracts perm.size() from an entry in perm to make it negative, which indicates the corresponding move has been performed.
				perm[next] -= perm.size();
				next = temp;
			}
		}

		// Restore perm.
		for_each(begin(perm), end(perm), [&perm](int& x) { x += perm.size(); });
	}
}