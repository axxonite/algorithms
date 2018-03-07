// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	int SearchSmallest( const vector<int>& a )
	{
		// There is a tricky corner case where the inversion is the first element (aka there is no inversion).
		// In this case it's imperative to keep left at zero, and to move right progressively toward the left.
		// This is why we MUST look for an inversion between mid and right. We must NOT look for an inversion between
		// left and mid, because a lack of inversion between left and mid does not necessarily mean there is an inversion
		// between mid and right.
		int left = 0, right = a.size() - 1;
		while ( left < right )
		{
			int mid = left + ( right - left ) / 2;
			if ( a[right] < a[mid] ) // look for the inversion. 
				left = mid + 1;
			else right = mid;
		}
		return left;
	}
}