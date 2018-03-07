// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

#define TEST 0

int SearchSmallest( const vector<int>& a ) 
{
	return 0;
}

#pragma region Test

void SearchSmallestSimpleTest() {
	vector<int> A = { 3, 1, 2 };
	assert( 1 == SearchSmallest( A ) );
	A = { 0, 2, 4, 8 };
	assert( 0 == SearchSmallest( A ) );
	A[0] = 16;
	assert( 1 == SearchSmallest( A ) );
	A = { 2, 3, 4 };
	assert( 0 == SearchSmallest( A ) );
	A = { 100, 101, 102, 2, 5 };
	assert( 3 == SearchSmallest( A ) );
	A = { 10, 20, 30, 40, 5 };
	assert( 4 == SearchSmallest( A ) );
}


void SearchSmallestTest()
{
#if TEST
	SearchSmallestSimpleTest();
	default_random_engine gen( ( random_device() )( ) );
	for ( int times = 0; times < 50; ++times ) {
		int n;
		uniform_int_distribution<int> dis( 1, 10000 );
		n = dis( gen );
		vector<int> A;
		unordered_set<int> table;
		for ( size_t i = 0; i < n; ++i )
		{
			while ( true )
			{
				uniform_int_distribution<int> dis( 0, 100000 );
				int x = dis( gen );
				if ( table.emplace( x ).second )
				{
					A.emplace_back( x );
					break;
				}
			}
		}
		sort( A.begin(), A.end() );
		uniform_int_distribution<int> n_dis( 0, n - 1 );
		int shift = n_dis( gen );
		reverse( A.begin(), A.end() );
		reverse( A.begin(), A.begin() + shift + 1 );
		reverse( A.begin() + shift + 1, A.end() );
		assert( ( shift + 1 ) % n == SearchSmallest( A ) );
	}
#endif
}

#pragma endregion
