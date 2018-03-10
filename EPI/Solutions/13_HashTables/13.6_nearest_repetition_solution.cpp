// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	int FindNearestRepetition( const vector<string>& paragraph )
	{
		unordered_map<string, int> lastLocation;
		int closest = numeric_limits<int>::max();
		for ( int i = 0; i < paragraph.size(); ++i )
		{
			auto it = lastLocation.find( paragraph[i] );
			if ( it != lastLocation.end() )
				closest = min( i - it->second, closest );
			lastLocation[paragraph[i]] = i;
		}
		return closest;
	}
}