// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

#define TEST 0

void RotateArray( int shift, vector<int>& a )
{
}

#pragma region Test

void RotateArrayTest()
{
#if TEST
	default_random_engine gen( ( random_device() )( ) );
	for ( int i = 0; i < 100; ++i )
	{
		uniform_int_distribution<int> dis( 200, 10000 );
		int n = dis( gen );
		uniform_int_distribution<int> dis2( 0, 100000 );
		int shift = dis2( gen );
		vector<int> a;
		for ( int j = 0; j < n; ++j )
		{
			a.emplace_back( dis2( gen ) );
		}

		vector<int> src = a;
		RotateArray( shift, a );
		for ( int j = 0; j < n; ++j )
		{
			assert( src[j] == a[( j + shift ) % a.size()] );
		}
	}

#endif
}

#pragma endregion Test
