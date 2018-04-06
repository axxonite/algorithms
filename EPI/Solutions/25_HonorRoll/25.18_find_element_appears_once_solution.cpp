// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	// We count the number of times each bit in the array as been set to one, modulo 3.
	// This has the effect of eliminating any set bits from elements that appear in triplicate,
	// while only leaving those bits that appeared with a single copy.
	// This is so elegant and simple. Using XORs was NOT the right approach here.

	// This is similar to simply putting the count of elements in a hash table, then scanning
	// for the element that only has a count of one. This performs the scan on a bitwise level
	// instead, using modulo 3 to eliminate triplets of bits set to one.
	int FindElementAppearsOnce( const vector<int> &A )
	{
		array<int, 32> counts = {};
		for ( int x : A )
		{
			for ( int i = 0; i < 32; ++i )
				if ( x & ( 1 << i ) )
					++counts[i];
		}
		int result = 0;
		for ( int i = 0; i < 32; ++i )
			result |= ( counts[i] % 3 ) * ( 1 << i );
		return result;
	}
}