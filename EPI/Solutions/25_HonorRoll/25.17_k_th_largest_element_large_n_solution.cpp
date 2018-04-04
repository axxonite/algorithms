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
				nth_element( values.begin(), values.begin() + k - 1, values.end(), greater<int>() );
				// Reset the index and overwrite any values above k.
				index = k; // k - 1 is the kth element, k is right past it.
			}
		}
		nth_element( values.begin(), values.begin() + k - 1, values.begin() + index, greater<int>() );
		return values[k - 1];
	}
}