// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

#define TEST 0

bool CanReachEnd( const vector<int>& a ) 
{
	return false;
}

#pragma region Test

void CanReachEndSmallTest() {
	vector<int> max_advance_steps = { 2, 3, 1, 1, 4 };
	assert( CanReachEnd( max_advance_steps ) );
	max_advance_steps = { 3, 2, 1, 0, 4 };
	assert( !CanReachEnd( max_advance_steps ) );
	max_advance_steps = { 3, 2, 1, -10, 4 };
	assert( !CanReachEnd( max_advance_steps ) );
	max_advance_steps = { 2, 3, -1, -1, 4 };
	assert( CanReachEnd( max_advance_steps ) );
	max_advance_steps = { 2, 2, -1, -1, 100 };
	assert( !CanReachEnd( max_advance_steps ) );
}

void CanReachEndTest()
{
#if TEST
	CanReachEndSmallTest();
	default_random_engine gen( ( random_device() )( ) );
	size_t n;
	uniform_int_distribution<size_t> dis( 1, 1000 );
	n = dis( gen );
	uniform_int_distribution<int> A_dis( 1, 10 );
	vector<int> max_advance_steps;
	generate_n( back_inserter( max_advance_steps ), n, [&] { return A_dis( gen ); } );
	cout << std::boolalpha << CanReachEnd( max_advance_steps ) << endl; 
#endif
}

#pragma endregion Test
