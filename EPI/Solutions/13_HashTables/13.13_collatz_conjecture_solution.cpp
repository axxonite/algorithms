// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	bool TestCollatzConjecture( int n )
	{
		// I'm using an unordered map to keep track of the when a number was last seen, to disambiguate whether it's the current cycle,
		// or a previous cycle. This does mean this will use more memory, but will exit out the loop sooner as we revisit values we 
		// know have already been proven. Either way is fine, depending on the trade offs we want, though the memory consumption for
		// this could be very large if we test for something like numeric_limits<int>::max().
		unordered_map<long long, int> tested;
		// Tricky.
		// Clever: because the even numbers always go to a previous number in the sequence, we don't need to test the even numbers.
		for ( int i = 3; i <= n; i += 2 )
		{
			long long v = i;
			while ( v >= i )
			{

				auto it = tested.find( v );
				if ( it != tested.end() )
				{
					if ( it->second == i )	// We've encountered a cycle.
						return false;
					break; // We've already tested this value.
				}
				tested[v] = i;
				if ( v % 2 == 0 )
					v /= 2;
				else
				{
					long long next = 3 * v + 1;
					// Notice the test for value - in this case we'd end up with a lesser value.
					if ( next < v )
						throw overflow_error( "overflow" );
					v = next;
				}
			}
			tested.erase( i );
			tested.erase( i + 1);
		}
		return true;
	}
}