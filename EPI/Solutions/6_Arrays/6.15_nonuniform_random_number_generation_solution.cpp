// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	int NonuniformRandomNumberGeneration( const vector<int>& values, const vector<double>& probabilities )
	{
		vector<double> sums{ 0.0 };
		// notice the use of the back_inserter trick.
		partial_sum( probabilities.begin(), probabilities.end(), back_inserter( sums ) );

		default_random_engine rnd( ( random_device() )( ) );

		// notice use of generate_canonical.
		auto value = generate_canonical<double, numeric_limits<double>::digits>( rnd ); // generate_canonical generates a number in range 0..1.
		// upper_bound effectively performs a binary search.
		int index = distance( sums.begin(), upper_bound( sums.begin(), sums.end(), value ) ) - 1; // upper_bound : first element of the range greater than value, which is why we need backtrack by one.
		return values[index];
	}
}