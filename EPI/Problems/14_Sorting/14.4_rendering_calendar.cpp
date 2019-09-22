// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

// #define TEST

struct Event 
{
	int start, finish;
};

int FindMaxSimultaneousEvents( const vector<Event>& a ) 
{
  return 0;
}

#pragma region Test

void FindMaxSimultaneousEventsSimpleTest()
{
	vector<Event> A = { { 1, 5 },{ 2, 7 },{ 4, 5 },{ 6, 10 },{ 8, 9 }, { 9, 17 },{ 11, 13 },{ 12, 15 },{ 14, 15 } };
	assert( FindMaxSimultaneousEvents( A ) == 3 );
	A = { { 1, 5 },{ 2, 7 },{ 4, 5 },{ 6, 10 },{ 8, 9 }, { 9, 17 },{ 11, 13 },{ 12, 15 },{ 14, 15 },{ 9, 10 } };
	assert( FindMaxSimultaneousEvents( A ) == 4 );
}

void FindMaxSimultaneousEventsTest()
{
#ifdef TEST
	FindMaxSimultaneousEventsSimpleTest();
	default_random_engine gen( ( random_device() )( ) );
	int n;
	uniform_int_distribution<int> dis( 1, 100000 );
	n = dis( gen );
	vector<Event> A;
	for ( int i = 0; i < n; ++i ) 
	{
		Event temp;
		uniform_int_distribution<int> dis1( 0, 99999 );
		temp.start = dis1( gen );
		uniform_int_distribution<int> dis2( temp.start + 1, temp.start + 10000 );
		temp.finish = dis2( gen );
		A.emplace_back( temp );
	}
	int ans = FindMaxSimultaneousEvents( A );
	cout << ans << endl;
#endif
}

#pragma endregion
