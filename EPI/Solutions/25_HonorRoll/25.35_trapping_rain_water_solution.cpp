// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	int TraverseHeights( const vector<int>& heights, int peak, int start, int inc )
	{
		int runningMax = 0, result = 0;
		for ( int i = start; i != peak; i += inc )
		{
			if ( heights[i] > runningMax )
				runningMax = heights[i];
			result += max( 0, min( runningMax, heights[peak] ) - heights[i] );
		}
		return result;
	}

	int CalculateTrappingWater( const vector<int>& heights )
	{
		int peak = 0, maxValue = 0;
		for ( int i = 0; i < heights.size(); ++i )
			if ( heights[i] > maxValue )
				peak = i, maxValue = heights[i];

		return TraverseHeights( heights, peak, 0, 1 ) + TraverseHeights( heights, peak, heights.size() - 1, -1 );
	}
}