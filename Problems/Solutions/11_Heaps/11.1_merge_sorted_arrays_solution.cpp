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

		for (const vector<int>& sorted_array : sortedArrays)
			if (!sorted_array.empty())
				minHeap.emplace(IteratorCurrentAndEnd{ sorted_array.cbegin(), sorted_array.cend() });

		vector<int> result;
		while (!minHeap.empty())
		{
			auto smallestArray = minHeap.top();
			minHeap.pop();
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
