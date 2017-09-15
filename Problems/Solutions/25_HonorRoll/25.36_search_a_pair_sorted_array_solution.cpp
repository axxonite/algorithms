// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	struct IndexPair
	{
		int index1, index2;
	};

	template <typename Compare>
	IndexPair FindPairUsingCompare(const vector<int>& a, int k, Compare comp)
	{
		// This path in the algorithm will attempt to match a two values of the same sign; positive if k >= 0, negative if k < 0
		// Casts are required here.
		// Start with left and right iterators for positive or negative values, depending on k.
		IndexPair result = IndexPair{ 0, static_cast<int>(a.size() - 1) };
		// Find first positive index1 (note, 0 is deemed positive)
		while (result.index1 < result.index2 && comp(a[result.index1], 0))
			++result.index1;
		// Find last positive index2
		while (result.index1 < result.index2 && comp(a[result.index2], 0))
			--result.index2;

		while (result.index1 < result.index2)
		{
			if (a[result.index1] + a[result.index2] == k)
				return result;
			// Note the use of the comparison here that depends on k
			if (comp(a[result.index1] + a[result.index2], k))
			{
				// If sum < k, move index1 to next positive index. This will increase the sum.
				do
					++result.index1;
				while (result.index1 < result.index2 && comp(a[result.index1], 0));
			}
			else
			{
				// If sum > k, move index2 to previous positive index. This will decrease the sum.
				do
					--result.index2;
				while (result.index1 < result.index2 && comp(a[result.index2], 0));
			}
		}
		return { -1, -1 }; // No answer.
	}

	IndexPair FindPositiveNegativePair(const vector<int>& a, int k)
	{
		// This path in the algorithm will attempt to match a positive value with a negative value to reach k.
		// Casts are required here.
		// Start from the right for both iterators, with index1 on the last positive value and index2 on the last negative value.
		IndexPair result = IndexPair{ static_cast<int>(a.size() - 1), static_cast<int>(a.size() - 1) };
		// Find the last positive or zero.
		while (result.index1 >= 0 && a[result.index1] < 0)
			--result.index1;
		// Find the last negative.
		while (result.index2 >= 0 && a[result.index2] >= 0)
			--result.index2;

		// Note how this line below is completely different from the same line for the function above.
		while (result.index1 >= 0 && result.index2 >= 0)
		{
			if (a[result.index1] + a[result.index2] == k)
				return result;
			if (a[result.index1] + a[result.index2] > k)
			{
				// If sum > k, move index1 to the next smaller positive value on the left. This will decrease the sum.
				do
					--result.index1;
				while (result.index1 >= 0 && a[result.index1] < 0);
			}
			else
			{
				// If sum < k, move index2 to the next smaller negative value on the left. This will increase the sum.
				do
					--result.index2;
				while (result.index2 >= 0 && a[result.index2] >= 0);
			}
		}
		return { -1, -1 }; // No answer.
	}

	IndexPair FindPairSumK(const vector<int>& a, int k)
	{
		IndexPair result = FindPositiveNegativePair(a, k);
		if (result.index1 == -1 && result.index2 == -1)
			return k >= 0 ? FindPairUsingCompare(a, k, less<int>()) : FindPairUsingCompare(a, k, greater_equal<int>());
		return result;
	}
}
