// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	struct LongestSpan
	{
		int h, w;
	};

	// A very difficult implementation.
	// The idea is based around avoiding computing solutions for areas where a better candidate is not possible.
	int MaxRectangleSubmatrix( const vector<deque<bool>>& a )
	{
		// Store, for each row and column, the longest span of 1s to the right or downward from the current cell.
		// Iterate starting from the bottom-right corner so we can accumulate spans in a single pass when we go to the left and up.
		vector<vector<LongestSpan>> longestSpans( a.size(), vector<LongestSpan>( a.front().size() ) );
		for (int i = a.size() - 1; i >= 0; --i)
		{
			for (int j = a[i].size() - 1; j >= 0; --j)
			{
				longestSpans[i][j] = a[i][j] ?
					// since we are going from right to left and from bottom to top, if we have a 1 in this cell, then the longest span for this cell is equal to 
					// the longest span for the next cell over, plus one.
					LongestSpan{	i + 1 < a.size() ? longestSpans[i + 1][j].h + 1 : 1, 
									j + 1 < a[i].size() ? longestSpans[i][j + 1].w + 1 : 1 } :
					LongestSpan{ 0, 0 }; // if we have a zero in this cell than ther span is zero.
			}
		}

		int best = 0;
		for (int i = 0; i < a.size(); ++i)
		{
			for (int j = 0; j < a[i].size(); ++j)
			{
				// The longest possible spans to the right and downward from this cell gives us an upper bound for the best possible rectangles we might find 
				// within that region starting from this cell. If that region's area is not larger than our current best candidate, then
				// don't bother testing that region any further.
				// if we have a one, and if we might have a better candidate from that cell...
				if (a[i][j] && longestSpans[i][j].w * longestSpans[i][j].h > best)
				{
					// Now iterate over every row of the longest vertical span and form rectangles from the top-left corner of the region, to the bottom-right
					// corner of the current row. The area of the rectangle is the height of the rectangle multiplied by the smallest horizontal span we've found thus far.
					int minWidth = numeric_limits<int>::max();
					for (int k = 0; k < longestSpans[i][j].h; ++k)
					{
						minWidth = min(minWidth, longestSpans[i + k][j].w);
						best = max(best, (k + 1) * minWidth); // note the k + 1, since k is an offset and is 0 for the first row in the rectangle.
					}
				}
			}
		}
		return best;
	}
}