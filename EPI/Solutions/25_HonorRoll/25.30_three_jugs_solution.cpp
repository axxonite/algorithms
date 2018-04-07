// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	struct Jug
	{
		int low, high;
	};

	struct VolumeRange
	{
		int l, h;

		bool operator == ( const VolumeRange& other ) const
		{
			return l == other.l && h == other.h;
		}
	};

	struct VolumeRangeHash
	{
		int operator() ( const VolumeRange& range ) const
		{
			return hash<int>()( range.l ) ^ hash<int>()( range.h );
		}
	};

	// Very elegant solution. I started by computing a running count as the jugs are added and removed, but it's much better to subtract
	// the range of the jug from the target range, until we either hit a negative range or find a jug that finds within the remaining range.
	// This also makes the unordered set much more efficient as it only needs to store a key based on two values.
	bool CheckFeasibleHelper( const vector<Jug>& jugs, int l, int h, unordered_set<VolumeRange, VolumeRangeHash> invalidResults )
	{
		// watch out for the range getting inverted! Also the whole range must be out of bounds for this range to become a deadend.
		if ( ( h < 0 && l < 0 ) || l > h || invalidResults.count( VolumeRange{ l, h } ) )
			return false;
		for ( const Jug& j : jugs )
			if ( ( j.low >= l && j.high <= h ) || CheckFeasibleHelper( jugs, l - j.low, h - j.high, invalidResults ) )
				return true;
		invalidResults.emplace( VolumeRange{ l, h } );
		return false;
	}

	bool CheckFeasible( const vector<Jug>& jugs, int l, int h )
	{
		unordered_set<VolumeRange, VolumeRangeHash> invalidResults;
		return CheckFeasibleHelper( jugs, l, h, invalidResults );
	}
}