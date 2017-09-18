// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	vector<double> global_result; // ?????? Fix this, we don't need this to be global.

	void OnlineMedian(istringstream* sequence)
	{
		priority_queue<int, vector<int>, greater<>> min_heap; // min_heap stores the larger half seen so far.
		priority_queue<int, vector<int>, less<>> max_heap; // max_heap stores the smaller half seen so far.

		int x;
		while (*sequence >> x)
		{
			min_heap.emplace(x);
			max_heap.emplace(min_heap.top());
			min_heap.pop();
			// Ensure min_heap and max_heap have equal number of elements if an even number of elements is read; otherwise, min_heap must have one more element than max_heap.
			if (max_heap.size() > min_heap.size())
			{
				min_heap.emplace(max_heap.top());
				max_heap.pop();
			}

			global_result.emplace_back(min_heap.size() == max_heap.size() ? 0.5 * (min_heap.top() + max_heap.top()) : min_heap.top());
		}
	}
}
