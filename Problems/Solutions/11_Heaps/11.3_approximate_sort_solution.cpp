// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	static vector<int> result;

	void SortApproximatelySortedData(istringstream* sequence, int k)
	{
		result = {};
		priority_queue<int, vector<int>, greater<>> min_heap;
		// Adds the first k elements into min_heap. Stop if there are fewer than k elements.
		int x;
		for (int i = 0; i < k && *sequence >> x; ++i)
			min_heap.push(x);

		// For every new element, add it to min_heap and extract the smallest.
		while (*sequence >> x)
		{
			min_heap.push(x);
			result.push_back(min_heap.top());
			min_heap.pop();
		}

		// sequence is exhausted, iteratively extracts the remaining elements.
		while (!min_heap.empty())
		{
			result.push_back(min_heap.top());
			min_heap.pop();
		}
	}
}
