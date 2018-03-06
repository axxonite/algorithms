// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	vector<int> MergeSortedArrays( const vector<vector<int>>& sortedArrays );

	// Note: the official implementation is VERY tricky. In an interview setting, I would reconsider doing it with the official implementation. It's much more error prone
	// than simply adding the values to new subarrays and reversing in a second pass.
	// This one seems simple, but is deceptively hard to get right.
	vector<int> SortKIncreasingDecreasingArray( const vector<int>& a )
	{
		vector<vector<int>> subarrays;
		int start = 0;
		// It turns out we can always assume the first subarray is ascending.
		// If the first two values are descending, we consider the first value a size-one subarray that is ascending, and the second value is the start of a new array.
		bool ascending = true;
		for ( int i = 1; i <= a.size(); ++i )
		{
			if ( i == a.size() || ascending != ( a[i] >= a[i - 1] ) )
			{
				if ( ascending )
					subarrays.emplace_back( a.cbegin() + start, a.cbegin() + i ); // TRICKY - the second iterator parameter is one past the last value we want to add.
																				  // TRICKY - crbegin() refers to the end iterator in the array - so we need to ADD the size of the vector then SUBTRACK the index we want.
																				  // Furthermore, the parameters are inverted with regards to what we would expect. The start parameter appears last since the order is reversed. Very tricky.
				else subarrays.emplace_back( a.crbegin() + a.size() - i, a.crbegin() + a.size() - start );
				start = i;
				ascending = !ascending;
			}
		}
		return Solutions::MergeSortedArrays( subarrays );
	}
}
