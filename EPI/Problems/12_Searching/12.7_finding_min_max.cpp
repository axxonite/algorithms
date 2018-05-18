// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

#define TEST 0

struct MinMax 
{
	int smallest, largest;
};

MinMax FindMinMax( const vector<int>& A ) 
{
	return { -1, -1 };
}

#pragma region Test

static void FindMinMaxSimpleTest() {
	vector<int> A = { -1, 3, -4, 6, 4, 10, 4, 4, 9 };
	auto res = FindMinMax( A );
	assert( -4 == res.smallest && 10 == res.largest );
	A[5] = -12;
	res = FindMinMax( A );
	assert( -12 == res.smallest && 9 == res.largest );
	A = { -1, 3, -4 };
	res = FindMinMax( A );
	assert( -4 == res.smallest && 3 == res.largest );
}

void FindMinMaxTest()
{
#if TEST
	FindMinMaxSimpleTest();
	default_random_engine gen( ( random_device() )( ) );
	for ( int times = 0; times < 100; ++times ) 
	{
		int n;
		uniform_int_distribution<int> dis( 1, 10000 );
		n = dis( gen );
		vector<int> A;
		for ( int i = 0; i < n; ++i ) 
		{
			uniform_int_distribution<int> dis( 0, 999999 );
			A.emplace_back( dis( gen ) );
		}
		MinMax res = FindMinMax( A );
		assert( res.smallest == *min_element( A.cbegin(), A.cend() ) && res.largest == *max_element( A.cbegin(), A.cend() ) );
	}
#endif
}

#pragma endregion
