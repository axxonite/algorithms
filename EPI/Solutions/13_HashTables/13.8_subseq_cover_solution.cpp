// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"
#include "Shared.h"

struct Subarray
{
	int start, end;
};

namespace Solutions
{
	Subarray FindSmallestSequentiallyCoveringSubset( const vector<string>& paragraph, const vector<string>& keywords )
	{
		Subarray result{ 0, numeric_limits<int>::max() };
		// Associate each keyword with the index for that keyword.
		unordered_map<string, int> keywordToIndex;
		for ( int i = 0; i < keywords.size(); ++i )
			keywordToIndex[keywords[i]] = i;

		// Keep the index of the first keyword in the subsequence, for the last subsequence found that includes the ith keyword.
		vector<int> subsequenceStart( keywords.size(), -1 );
		for ( int i = 0; i < paragraph.size(); ++i )
		{
			auto it = keywordToIndex.find( paragraph[i] );
			if ( it != keywordToIndex.end() )
			{
				if ( it->second == 0 )
					subsequenceStart[0] = i;
				else if ( subsequenceStart[it->second - 1] != -1 ) // Do we have an active subsequence for the prior keywords?
				{
					if ( it->second == keywords.size() - 1 && ( i - subsequenceStart[it->second - 1] ) < ( result.end - result.start ) )
						result = { subsequenceStart[it->second - 1], i };
					else subsequenceStart[it->second] = subsequenceStart[it->second - 1]; // If so, extend the coverage of the subsequence.
				}
			}
		}
		return result.end == numeric_limits<int>::max() ? Subarray{ -1, -1 } : result;
	}
}