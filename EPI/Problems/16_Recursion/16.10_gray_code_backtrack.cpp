// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

#define TEST 0

vector<int> GrayCode( int num_bits )
{
	return {};
}

#pragma region Test

void GrayCodeSmallTest()
{
	auto vec = GrayCode( 3 );
	vector<int> expected = { 0, 1, 3, 2, 6, 7, 5, 4 };
	assert( equal( vec.begin(), vec.end(), expected.begin(), expected.end() ) );
}

void CheckAns( const vector<int>& A )
{
	for ( size_t i = 0; i < A.size(); ++i )
	{
		int num_differ_bits = 0;
		bitset<10> prev( A[i] ), now( A[( i + 1 ) % A.size()] );
		string prev_s = prev.to_string(), now_s = now.to_string();
		for ( size_t i = 0; i < 10; ++i )
		{
			if ( prev_s[i] != now_s[i] )
				++num_differ_bits;
		}
		assert( num_differ_bits == 1 );
	}
}


void GrayCodeTest()
{
#if TEST
	GrayCodeSmallTest();
	default_random_engine gen( ( random_device() )( ) );
	int n;
	uniform_int_distribution<int> dis( 1, 9 );
	n = dis( gen );
	cout << "n = " << n << endl;
	auto vec = GrayCode( n );
	for ( int a : vec )
		cout << a << endl;
	CheckAns( vec );
#endif
}

#pragma endregion
