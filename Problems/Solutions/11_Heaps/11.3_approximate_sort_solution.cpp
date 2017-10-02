// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	vector<int> SortApproximatelySortedData(istringstream* sequence, int k)
	{
		vector<int> result;
		priority_queue<int, vector<int>, greater<>> minHeap;
		// Adds the first k elements into minHeap. Stop if there are fewer than k elements.
		int x;
		for (int i = 0; i < k && *sequence >> x; ++i)
			minHeap.push(x);

		// For every new element, add it to min_Hap and extract the smallest.
		while (*sequence >> x)
		{
			minHeap.push(x);
			result.push_back(minHeap.top());
			minHeap.pop();
		}

		// sequence is exhausted, iteratively extracts the remaining elements.
		while (!minHeap.empty())
		{
			result.push_back(minHeap.top());
			minHeap.pop();
		}
		return result;
	}
}
