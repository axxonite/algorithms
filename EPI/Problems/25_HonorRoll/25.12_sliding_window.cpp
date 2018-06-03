// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

#define TEST 0

struct TrafficElement 
{
	int time;
	double volume;

	bool operator==( const TrafficElement& that ) const 
	{
		return time == that.time && volume == that.volume;
	}
};

vector<TrafficElement> CalculateTrafficVolumes(const vector<TrafficElement>& A, int w ) 
{
	return {};
}

#pragma region Test

void CalculateTrafficVolumesTest()
{
#if TEST
	int w = 3;
	vector<TrafficElement> A = {
		TrafficElement{ 0, 1.3 }, TrafficElement{ 2, 2.5 }, TrafficElement{ 3, 3.7 },
		TrafficElement{ 5, 1.4 }, TrafficElement{ 6, 2.6 }, TrafficElement{ 8, 2.2 },
		TrafficElement{ 9, 1.7 }, TrafficElement{ 14, 1.1 } };
	auto result = CalculateTrafficVolumes( A, w );
	vector<TrafficElement> golden = {
		TrafficElement{ 0, 1.3 }, TrafficElement{ 2, 2.5 }, TrafficElement{ 3, 3.7 },
		TrafficElement{ 5, 3.7 }, TrafficElement{ 6, 3.7 }, TrafficElement{ 8, 2.6 },
		TrafficElement{ 9, 2.6 }, TrafficElement{ 14, 1.1 } };
	assert( equal( golden.begin(), golden.end(), result.begin(), result.end() ) ); 
#endif
}

#pragma endregion