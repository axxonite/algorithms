// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	const int kMPG = 20;

	// gallons[i] is the amount of gas in city i, and distances[i] is the distance city i to the next city.
	size_t FindAmpleCity( const vector<int>& gallons, const vector<int>& distances )
	{
		// City 0 start with zero gas. It does NOT start with the gas in the first city.
		// City 0 will starts as the candidate ample city, and will remain so if we find no other city where we end up with less gas.
		int minGas = 0, gas = 0, ampleCity = 0;
		for ( int i = 1; i < gallons.size(); ++i )
		{
			// Fill up in the previous city, and drive here.
			gas += gallons[i - 1] - distances[i - 1] / kMPG;
			if ( gas < minGas )
			{
				minGas = gas;
				ampleCity = i;
			}
		}
		return ampleCity;
	}
}