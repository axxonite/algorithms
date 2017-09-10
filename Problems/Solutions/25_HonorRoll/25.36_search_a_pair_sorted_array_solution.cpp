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
		IndexPair result = IndexPair{ 0, static_cast<int>(a.size() - 1) };
		while (result.index1 < result.index2 && comp(a[result.index1], 0))
			++result.index1;
		while (result.index1 < result.index2 && comp(a[result.index2], 0))
			--result.index2;

		while (result.index1 < result.index2)
		{
			if (a[result.index1] + a[result.index2] == k)
				return result;
			if (comp(a[result.index1] + a[result.index2], k))
			{
				do
					++result.index1;
				while (result.index1 < result.index2 && comp(a[result.index1], 0));
			}
			else
			{
				do
					--result.index2;
				while (result.index1 < result.index2 && comp(a[result.index2], 0));
			}
		}
		return { -1, -1 }; // No answer.
	}

	IndexPair FindPositiveNegativePair(const vector<int>& a, int k)
	{
		// result.index1 for positive, and result.index2 for negative.
		IndexPair result = IndexPair{ static_cast<int>(a.size() - 1), static_cast<int>(a.size() - 1) };
		// Find the last positive or zero.
		while (result.index1 >= 0 && a[result.index1] < 0)
			--result.index1;

		// Find the last negative.
		while (result.index2 >= 0 && a[result.index2] >= 0)
			--result.index2;

		while (result.index1 >= 0 && result.index2 >= 0)
		{
			if (a[result.index1] + a[result.index2] == k)
				return result;
			if (a[result.index1] + a[result.index2] > k)
			{
				do
					--result.index1;
				while (result.index1 >= 0 && a[result.index1] < 0);
			}
			else
			{ // a[result.index1] + a[result.index2] < k.
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
