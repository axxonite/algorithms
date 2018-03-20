// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

#define TEST 0

const int kMPG = 20;

// gallons[i] is the amount of gas in city i, and distances[i] is the distance city i to the next city.
size_t FindAmpleCity( const vector<int>& gallons, const vector<int>& distances )
{
	return 0;
}

#pragma region Test

void FindAmpleCityCheckAns( const vector<int>& gallons, const vector<int>& distances,
	size_t c ) {
	size_t s = c;
	int gas = 0;
	do 
	{
		gas += gallons[s] - distances[s] / kMPG;
		assert( gas >= 0 );
		s = ( s + 1 ) % gallons.size();
	} 
	while ( s != c );
}

void FindAmpleCitySmallTest() 
{
	// Example in the book.
	vector<int> gallons = { 20, 15, 15, 15, 35, 25, 30, 15, 65, 45, 10, 45, 25 };
	vector<int> distances = { 15 * kMPG, 20 * kMPG, 50 * kMPG, 15 * kMPG,
		15 * kMPG, 30 * kMPG, 20 * kMPG, 55 * kMPG,
		20 * kMPG, 50 * kMPG, 10 * kMPG, 15 * kMPG,
		15 * kMPG };
	size_t ans = FindAmpleCity( gallons, distances );
	assert( ans == 8 );
	FindAmpleCityCheckAns( gallons, distances, ans );
}

void FindAmpleCityTest()
{
#if TEST
	FindAmpleCitySmallTest();
	default_random_engine gen( ( random_device() )( ) );
	for ( int times = 0; times < 1000; ++times )
	{
		int n;
		uniform_int_distribution<int> dis( 1, 10000 );
		n = dis( gen );
		vector<int> gallons, distances;
		int sum = 0;
		for ( int i = 0; i < n; ++i ) {
			uniform_int_distribution<int> dis( 1, 200 );
			int x = dis( gen );
			sum += x;
			gallons.emplace_back( x );
		}
		sum -= n;
		for ( int i = 0; i < n; ++i )
		{
			int x = 0;
			if ( sum )
			{
				uniform_int_distribution<int> dis( 1, sum );
				x = dis( gen );
			}
			distances.emplace_back( x + 1 );
			sum -= x;
		}
		distances.back() += sum;
		size_t c = FindAmpleCity( gallons, distances );
		cout << "start city = " << c << endl;
		FindAmpleCityCheckAns( gallons, distances, c );
	}
#endif
}

#pragma endregion
