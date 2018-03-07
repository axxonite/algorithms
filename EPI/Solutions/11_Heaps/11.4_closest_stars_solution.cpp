// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	struct Star
	{
		bool operator<( const Star& that ) const
		{
			return Distance() < that.Distance();
		}

		double Distance() const { return sqrt( x * x + y * y + z * z ); } // why use a square root here?

		double x, y, z;
	};

	// Overall, somewhat tricky to get just right. The devil is in the details.
	vector<Star> FindClosestKStars( int k, istringstream* stars )
	{
		priority_queue<Star, vector<Star>> heap;
		vector<Star> result;
		double x, y, z;
		string line;
		while ( getline( *stars, line ) )
		{
			stringstream lineStream( line );
			string token;
			getline( lineStream, token, ',' );
			x = stod( token );
			getline( lineStream, token, ',' );
			y = stod( token );
			getline( lineStream, token, ',' );
			z = stod( token );

			// Note how much cleaner it is to emplace first, then pop if the heap has a size greater than k.
			heap.emplace( Star{ x, y, z } );
			if ( heap.size() > k )
				heap.pop();
		}
		while ( !heap.empty() )
		{
			result.emplace_back( heap.top() );
			heap.pop();
		}
		return { result.rbegin(), result.rend() }; // We want a specific order here, so we have to reverse the order at the end to get the closest stars first.
	}
}