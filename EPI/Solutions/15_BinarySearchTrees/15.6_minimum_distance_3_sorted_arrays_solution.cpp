// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	int FindClosestElementsInSortedArrays(const vector<vector<int>>& arrays)
	{
		int minSoFar = numeric_limits<int>::max();

		struct IterTail
		{
			vector<int>::const_iterator iter, tail;
		};
		// Stores two iterators in each entry. One for traversing, and the other to check if we reached the end. This stores iterators and tails from each array.
		multimap<int, IterTail> iterAndTail;
		// Initialize the iterators and tails for each array, with the key set as the first (minimum) value from each array.
		for (const vector<int>& array : arrays)
			iterAndTail.emplace(array.front(), IterTail{ array.cbegin(), array.cend() });

		while (true)
		{
			int minValue = iterAndTail.cbegin()->first, maxValue = iterAndTail.crbegin()->first;
			minSoFar = min(maxValue - minValue, minSoFar);
			
			// Advance the iterator for the array with the minimum value.
			const auto nextMin = next(iterAndTail.cbegin()->second.iter), nextEnd = iterAndTail.cbegin()->second.tail;
			// Return if some array has no remaining elements.
			if (nextMin == nextEnd)
				return minSoFar;
			// Add the updated iterator for the given array.
			iterAndTail.emplace(*nextMin, IterTail{ nextMin, nextEnd });
			// Remove the reference to the told iterator we just removed.
			// What a weird, counter intuitive way to to do this.
			iterAndTail.erase(iterAndTail.cbegin());
		}
	}
}
