// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	vector<int> KLargestInBinaryHeap(const vector<int>& A, int k)
	{
		if (k <= 0)
			return {};

		struct HeapEntry
		{
			int index, value;
		};
		priority_queue<HeapEntry, vector<HeapEntry>, function<bool(HeapEntry, HeapEntry)>> candidateMaxHeap([](const HeapEntry& a, const HeapEntry& b) { return a.value < b.value; });

		// The largest element in A is at index 0.
		candidateMaxHeap.emplace(HeapEntry{ 0, A[0] });
		vector<int> result;
		for (int i = 0; i < k; ++i)
		{
			int candidateIndex = candidateMaxHeap.top().index;
			result.emplace_back(candidateMaxHeap.top().value);
			candidateMaxHeap.pop();

			int leftChildIndex = 2 * candidateIndex + 1;
			if (leftChildIndex < A.size())
				candidateMaxHeap.emplace(HeapEntry{ leftChildIndex, A[leftChildIndex] });
			int rightChildIndex = 2 * candidateIndex + 2;
			if (rightChildIndex < A.size())
				candidateMaxHeap.emplace(HeapEntry{ rightChildIndex, A[rightChildIndex] });
		}
		return result;
	}
}
