// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	int SearchEntryEqualToItsIndex( const vector<int>& a )
	{
		int left = 0, right = a.size() - 1;
		while ( left <= right )
		{
			int mid = ( left + right ) / 2;
			int value = a[mid] - mid;
			if ( value > 0 )
				right = mid - 1;
			else if ( value < 0 )
				left = mid + 1;
			else return mid;
		}
		return -1;
	}
}