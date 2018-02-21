// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	bool CanReachEnd( const vector<int>& a )
	{
		int maxReachable = 0;
		for ( int i = 0; i <= maxReachable && i < a.size(); ++i )
			maxReachable = max( maxReachable, i + a[i] );
		return maxReachable >= a.size() - 1;
	}
}