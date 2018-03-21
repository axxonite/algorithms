// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	vector<int> GrayCode( int n )
	{
		if ( n == 0 )
			return { 0 };
		auto result = GrayCode( n - 1 );
		// Build solution iteratively for a cleaner solution.
		for ( int i = result.size() - 1; i >= 0; --i )
			result.emplace_back( result[i] | ( 1 << ( n - 1 ) ) );
		return result;
	}
}