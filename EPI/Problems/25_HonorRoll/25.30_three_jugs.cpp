// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

#define TEST 0

struct Jug 
{
	int low, high;
};

bool CheckFeasible( const vector<Jug>& jugs, int L, int H ) 
{
	return false;
}

#pragma region Test

void CheckFeasibleTest()
{
#if TEST
	int n;
	vector<Jug> jugs = { { 230, 240 },{ 290, 310 },{ 500, 515 } };
	assert( CheckFeasible( jugs, 2100, 2300 ) == true );
	jugs.clear();
	default_random_engine gen( ( random_device() )( ) );
	uniform_int_distribution<int> dis( 1, 100 );
	n = dis( gen );
	for ( int i = 0; i < n; ++i ) 
	{
		Jug t;
		uniform_int_distribution<int> dis1( 0, 999 );
		t.low = dis1( gen );
		uniform_int_distribution<int> dis2( t.low + 1, t.low + 20 );
		t.high = dis2( gen );
		jugs.emplace_back( t );
	}
	uniform_int_distribution<int> dis1( 0, 9999 );
	int l = dis1( gen );
	uniform_int_distribution<int> dis2( l + 1, l + 5000 );
	int h = dis2( gen );
	cout << boolalpha << CheckFeasible( jugs, l, h ) << endl;
#endif
}

#pragma endregion
