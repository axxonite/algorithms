// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	struct Subarray
	{
		int start = 0, end = 0;
	};

	// The idea here is that if we have a candidate for longest sequence that is 1000 values long, then we want to early out as soon as possible once we see we
	// don't have a chance to get to at least 1000 increasing values. That means starting from the end of a candidate subarray that is 1000 values long and backtracking.
	//
	// In the real world? My bet is it's not any faster, at least on the data sets we have in the test here. Runs of increasing values are only 6-10 entries long.
	// Cache coherency will dominate the cost of this algorithm, and with a cache line size of 64, we're going to be fetching 16 values whenever we access a new memory
	// access boundary anyway. On top of it, there's a lot of cycles spent going forward and backtracking, so this might actually be slower.
	Subarray FindLongestIncreasingSubarray( const vector<int>& a )
	{
		Subarray result = { 0, 0 };
		int bestLength = 1, i = 0;
		// If we would have to go past the length of the input array a to do better than our current best solution, then exit out; we have already found the best
		// solution we can.
		while ( i + bestLength < a.size() )
		{
			bool isBetterCandidate = true;
			// We have a best result of size length, we need a result of size length + 1 at least.
			for ( int j = i + bestLength; j > i; --j )
			{
				if ( a[j] <= a[j - 1] )
				{
					// We've found a value that isn't increasing, which means the subarray starting at i and ending at i + bestLength is not
					// an increasing subsequence. Hence, the subarray starting at i cannot be a better value, and neither can be any subarray
					// starting between i and j, because there is a break in the sequence at j. We know that the subarray from j to i+length
					// is an increasing subarray, so we could potentially have a valid solution starting from j. So we set i to j. This is the tricky part.
					isBetterCandidate = false;
					i = j;
					break;
				}
			}

			if ( isBetterCandidate )
			{
				// We know the subarray [i, i+bestLength] is a better solution than what we currently have. Check if can extend the subarray further on the right.
				int j = i + bestLength + 1;
				while ( j < a.size() && a[j] > a[j - 1] )
					++j;
				result = { i, j - 1 }; // j is just past the last entry in the solution subarray.
				bestLength = j - 1 - i; // Don't forget to update the best length!
				i = j; // Set i to the next increasing subsequence.
			}
		}
		return result;
	}
}