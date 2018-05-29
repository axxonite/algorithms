// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	int SearchSmallest( const vector<int>& a )
	{
		// left tracks a candidate for the smallest element.
		// There is a tricky corner case where the inversion is the first element (aka there is no inversion).
		// In this case it's imperative to keep left at zero, and to move right progressively toward the left.
		// This is why we MUST look for an inversion between mid and right. We must NOT look for an inversion between
		// left and mid, because a lack of inversion between left and mid does not necessarily mean there is an inversion
		// between mid and right.

		// Focus on the range where the solution may lie.
		int left = 0, right = a.size() - 1;
		while ( left < right )
		{
			int mid = left + ( right - left ) / 2;
			if (a[mid] < a[right]) // there is no inversion on the right, so the smallest value must be somewhere within [left, mid] (aka mid could still be the smallest value.
				right = mid;
			else left = mid + 1; // there is an inversion on the right, so the smallest value must be somewhere within [mid + 1, right].
		}
		return left;
	}
}