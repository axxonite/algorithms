// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	int BinarySearchUnknownLength(const vector<int>& a, int k)
	{
		// find length
		int bitIndex = 0;
		while (true)
		{
			int index = (1 << bitIndex) - 1;
			if (index >= a.size() || a[index] > k)
				break;
			if (a[index] == k)
				return index;
			++bitIndex;
		}
		// This is the key aspect in this algorith. We have tested all ranges from 2^(i-1)..2^(i)-1.
		// That means the value cannot be in an index < 2^(i-1). It's imperative of thinking of the binary search as testing particular subranges of the array, which do not necessarily start at zero.
		// range is 0, index. index may be > size, k is definitely on the left side, if it exists.
		int left = max(0, (1 << (bitIndex - 1)) - 1), right = (1 << bitIndex) - 1;
		// We continue until left > right so that we test the value even if there is only candidate value. right is the last value in the subarray.
		// Binary seach implementations need more practice. Tricky.
		while (left <= right)
		{
			int mid = (left + right) / 2;
			// The exception handling is not working due to some STL issues so I am checking the size explicity here.
			// if we're out of bounds, move the right boundary.
			if (mid >= a.size() || a[mid] > k)
				right = mid - 1;
			else if (a[mid] == k) // return if we found our value.
				return mid;
			else if (a[mid] < k) // Move the left boundary if our current mid value is less than k.
				left = mid + 1;
		}
		return -1;
	}
}