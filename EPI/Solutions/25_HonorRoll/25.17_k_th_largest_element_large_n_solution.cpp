// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	// k starts at 1.
	int FindKthLargestUnknownLength( istringstream* stream, int k )
	{
		// Stream in values into an array of size 2k. Once the array is full, partition it to find k.
		// Then stream in another k values, and repeat.
		vector<int> values( 2 * k );
		int index = 0, x = 0;
		while ( *stream >> x )
		{
			values[index++] = x;
			if ( index == values.size() )
			{
				// Partition the array. K starts at 1 by convention, so subtract one to get the index in the array which starts at zero.
				// After the partition, all elements greater than k are after k. We can discard those values.
				// Note that we are looking for the kth greatest element, hence we are using the greater<> predicate here.
				nth_element( values.begin(), values.begin() + k - 1, values.end(), greater<int>() );
				// Reset the index and overwrite any values above k.
				index = k; // k - 1 is the kth element, k is right past it.
			}
		}
		// Note here that the upper bound of the partition at index, not values.end(), because we may not have filled 2k elements at this point.
		nth_element( values.begin(), values.begin() + k - 1, values.begin() + index, greater<int>() );
		return values[k - 1];
	}
}