// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	int FindClosestElementsInSortedArrays(const vector<vector<int>>& sorted_arrays)
	{
		int min_distance_so_far = numeric_limits<int>::max();

		struct IterTail
		{
			vector<int>::const_iterator iter, tail;
		};
		// Stores two iterators in each entry. One for traversing, and the other to check we reach the end.
		multimap<int, IterTail> iter_and_tail;
		for (const vector<int>& sorted_array : sorted_arrays)
			iter_and_tail.emplace(sorted_array.front(), IterTail{ sorted_array.cbegin(), sorted_array.cend() });

		while (true)
		{
			int min_value = iter_and_tail.cbegin()->first, max_value = iter_and_tail.crbegin()->first;
			min_distance_so_far = min(max_value - min_value, min_distance_so_far);
			const auto next_min = next(iter_and_tail.cbegin()->second.iter), next_end = iter_and_tail.cbegin()->second.tail;
			// Return if some array has no remaining elements.
			if (next_min == next_end)
				return min_distance_so_far;
			iter_and_tail.emplace(*next_min, IterTail{ next_min, next_end });
			iter_and_tail.erase(iter_and_tail.cbegin());
		}
	}
}
