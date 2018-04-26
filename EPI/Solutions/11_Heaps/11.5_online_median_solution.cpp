// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	vector<double> globalResult;

	void OnlineMedian(istringstream* sequence)
	{
		priority_queue<int, vector<int>, greater<>> minHeap; // min_heap stores the larger half seen so far.
		priority_queue<int, vector<int>, less<>> maxHeap; // max_heap stores the smaller half seen so far.

		int x;
		while (*sequence >> x)
		{
			// The count for the heaps for each element inserted is [min1, max0], [min1, max1], [min2, max1], and so forth.
			minHeap.emplace(x); // add to min heap.
			maxHeap.emplace(minHeap.top()); // transfer smallest value in min heap to max heap.
			minHeap.pop();
			// Ensure minHeap and maxHeap have equal number of elements if an even number of elements is read; otherwise, minHeap must have one more element than maxHeap.
			if (maxHeap.size() > minHeap.size())
			{
				minHeap.emplace(maxHeap.top()); // transfer greatest value in max heap to min heap.
				maxHeap.pop();
			}

			// for even numbers of elements, take the average of the top values in each heap, for odd number of elements, take the top value from the min heap where the last element was inserted.
			globalResult.emplace_back(minHeap.size() == maxHeap.size() ? 0.5 * (minHeap.top() + maxHeap.top()) : minHeap.top());
		}
	}
}
