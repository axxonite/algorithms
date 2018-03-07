// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	struct MinMax
	{
		int smallest, largest;
	};

	// Note the use of the minmax function to keep everything really short.
	MinMax FindMinMax( const vector<int>& a )
	{
		if ( a.size() < 2 )
			return { a.front(), a.front() };
		pair<int, int> result = minmax( a[0], a[1] );
		for ( int i = 2; i + 1 < a.size(); i += 2 )
		{
			pair<int, int> local = minmax( a[i], a[i + 1] );
			result = { min( result.first, local.first ), max( result.second, local.second ) };
		}
		if ( a.size() % 2 )
			result = { min( result.first, a.back() ), max( result.second, a.back() ) };
		return { result.first, result.second };
	}
}