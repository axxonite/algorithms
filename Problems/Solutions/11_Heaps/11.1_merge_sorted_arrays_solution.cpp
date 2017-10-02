// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	struct IteratorCurrentAndEnd
	{
		bool operator>(const IteratorCurrentAndEnd& that) const
		{
			return *current > *that.current;
		}

		vector<int>::const_iterator current;
		vector<int>::const_iterator end;
	};

	vector<int> MergeSortedArrays(const vector<vector<int>>& sortedArrays)
	{
		priority_queue<IteratorCurrentAndEnd, vector<IteratorCurrentAndEnd>, greater<>> minHeap;

		for (const vector<int>& a : sortedArrays)
			if (!a.empty()) // don't forget to check whether the array is empty.
				minHeap.emplace(IteratorCurrentAndEnd{ a.cbegin(), a.cend() });

		vector<int> result;
		while (!minHeap.empty())
		{
			auto smallestArray = minHeap.top();
			minHeap.pop();
			// If we haven't reached the end of that array, then put the next smallest element from that array in the min heap.
			if (smallestArray.current != smallestArray.end)
			{
				result.emplace_back(*smallestArray.current);
				minHeap.emplace(IteratorCurrentAndEnd{ next(smallestArray.current), smallestArray.end });
			}
		}
		return result;
	}

	// no test
}
