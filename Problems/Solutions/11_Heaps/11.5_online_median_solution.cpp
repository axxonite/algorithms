// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	vector<double> globalResult; // ?????? Fix this, we don't need this to be global.

	void OnlineMedian(istringstream* sequence)
	{
		priority_queue<int, vector<int>, greater<>> minHeap; // min_heap stores the larger half seen so far.
		priority_queue<int, vector<int>, less<>> maxHeap; // max_heap stores the smaller half seen so far.

		int x;
		while (*sequence >> x)
		{
			minHeap.emplace(x); // add to min heap.
			maxHeap.emplace(minHeap.top()); // transfer min heap top to max heap.
			minHeap.pop();
			// Ensure minHeap and maxHeap have equal number of elements if an even number of elements is read; otherwise, minHeap must have one more element than maxHeap.
			// in other words, every second element should go to the min heap.
			if (maxHeap.size() > minHeap.size())
			{
				minHeap.emplace(maxHeap.top());
				maxHeap.pop();
			}

			// for even numbers of elements, take the average of the top values in each heap, for odd number of elements, take the top value from the min heap where the last element was inserted.
			globalResult.emplace_back(minHeap.size() == maxHeap.size() ? 0.5 * (minHeap.top() + maxHeap.top()) : minHeap.top());
		}
	}
}
