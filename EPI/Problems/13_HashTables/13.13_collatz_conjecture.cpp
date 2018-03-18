// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

#define TEST 0

bool TestCollatzConjecture( int n ) 
{
	return false;
}

#pragma region Test

// Slow check without any pruning.
bool TestCollatzConjectureCheck( int n ) 
{
	for ( int i = 2; i <= n; ++i ) 
	{
		int test_i = i;
		while ( test_i != 1 && test_i >= i ) 
		{
			if ( test_i % 2 ) 
				test_i = test_i * 3 + 1;
			else test_i >>= 1;
		}
	}
	return true;
}

void TestCollatzConjectureTest()
{
#if TEST
	default_random_engine gen( ( random_device() )( ) );
	for ( int times = 0; times < 5; ++times ) 
	{
		int n;
		uniform_int_distribution<int> dis( 1, 100000 );
		n = dis( gen );
		cout << "n = " << n << endl;
		bool res;
		cout << boolalpha << ( res = TestCollatzConjecture( n ) ) << endl;
		assert( res == TestCollatzConjectureCheck( n ) );
	}
#endif
}

#pragma endregion