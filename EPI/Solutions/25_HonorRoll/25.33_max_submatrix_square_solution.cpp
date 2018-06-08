// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	struct LongestSpan
	{
		int h, w;
	};

	int MaxSquareSubmatrix( const vector<deque<bool>>& a )
	{
		// Store, for each row and column, the longest span of 1s to the right or downward from the current cell.
		// Iterate starting from the bottom-right corner so we can accumulate spans in a single pass when we go to the left and up.
		vector<vector<LongestSpan>> longestSpans( a.size(), vector<LongestSpan>( a.front().size() ) );
		for ( int i = a.size() - 1; i >= 0; --i )
		{
			for ( int j = a[i].size() - 1; j >= 0; --j )
			{
				longestSpans[i][j] = a[i][j] ?
					LongestSpan{ i + 1 < a.size() ? longestSpans[i + 1][j].h + 1 : 1, j + 1 < a[i].size() ? longestSpans[i][j + 1].w + 1 : 1 } :
					LongestSpan{ 0, 0 };
			}
		}

		vector<vector<int>> largestSquareSide( a.size(), vector<int>( a.front().size(), 0 ) );
		int best = 1;
		for ( int i = a.size() - 1; i >= 0; --i )
		{
			for ( int j = a[i].size() - 1; j >= 0; --j )
			{
				if ( a[i][j] )
				{
					if ( i + 1 < a.size() && j + 1 < a[i + 1].size() ) // ha man, look at that +1 on the second size... this will matter if we have uneven rows.
						largestSquareSide[i][j] = min( min( longestSpans[i][j].w, longestSpans[i][j].h ), largestSquareSide[i + 1][j + 1] + 1 );
					else largestSquareSide[i][j] = 1;
					best = max( best, largestSquareSide[i][j] * largestSquareSide[i][j] );
				}
			}
		}
		return best;
	}
}