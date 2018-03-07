// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	int SearchFirstOfK( const vector<int>& a, int k )
	{
		int left = 0, right = a.size() - 1;
		int result = -1;
		// Update left so that its ends up >= k.
		while ( left <= right ) // Make sure to do one iteration on =, so we update result.
		{
			int mid = ( left + right ) / 2;
			if ( a[mid] < k ) // k can't be at mid or before, so update left to + 1.
				left = mid + 1;
			else if ( a[mid] > k )
				right = mid - 1;
			else
			{
				result = mid;
				right = mid - 1;
			}
		}
		return result;
	}
}