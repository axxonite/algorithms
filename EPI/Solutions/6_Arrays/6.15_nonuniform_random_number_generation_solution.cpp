// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	int NonuniformRandomNumberGeneration( const vector<int>& values, const vector<double>& probabilities )
	{
		vector<double> sums;
		// notice the use of the back_inserter trick.
		// A value will be selected if we draw a normalized random value between sums[i] and sums[i + 1]
		partial_sum( probabilities.begin(), probabilities.end(), sums.begin() );

		default_random_engine rnd( ( random_device() )( ) );

		// notice use of generate_canonical.
		auto value = generate_canonical<double, numeric_limits<double>::digits>( rnd ); // generate_canonical generates a number in range 0..1.
		// upper_bound effectively performs a binary search.
		// note that we must have the leftmost iterator as the first argument in the distance function.
		int index = distance( sums.begin(), upper_bound( sums.begin(), sums.end(), value ) );
		return values[index];
	}
}