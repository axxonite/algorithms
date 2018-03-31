// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	struct TrafficElement
	{
		int time;
		double volume;

		bool operator==( const TrafficElement& that ) const
		{
			return time == that.time && volume == that.volume;
		}
	};

	// Perfect score on this one :). In fact I did even better than the book, assuming the time stamps are in order.
	vector<TrafficElement> CalculateTrafficVolumes( const vector<TrafficElement>& A, int w )
	{
		vector<TrafficElement> result;
		deque<TrafficElement> q;
		for ( auto a : A )
		{
			while ( !q.empty() && q.back().volume < a.volume )
				q.pop_back();
			q.push_back( a );
			while ( a.time - q.front().time > w )
				q.pop_front();
			result.emplace_back( TrafficElement{ a.time, q.front().volume } );
		}
		return result;
	}
}