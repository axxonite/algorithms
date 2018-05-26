// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	const int kMPG = 20;

	// gallons[i] is the amount of gas in city i, and distances[i] is the distance city i to the next city.
	size_t FindAmpleCity( const vector<int>& gallons, const vector<int>& distances )
	{
		// City 0 start with zero gas. It does NOT start with the gas in the first city.
		int gas = 0, lowestGas = 0, ampleCity = 0;
		// City 0 will starts as the candidate ample city, and will remain so if we find no other city where we end up with less gas.
		for (int i = 0; i < gallons.size(); ++i) // i is the city where we've arrived.
		{
			if (gas > lowestGas)
				lowestGas = gas, ampleCity = i;
			gas = gas + gallons[i] - distances[i] / kMPG;
		}
		return ampleCity;
	}
}