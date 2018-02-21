// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

#define TEST 0

double BuyAndSellStockOnce( const vector<double>& prices ) 
{
	return 0;
}

#pragma region Test

// O(n^2) checking answer.
double BuyAndSellStockOnceCheckAns( const vector<double>& h ) {
	double cap = 0;
	for ( int i = 1; i < h.size(); ++i ) 
	{
		for ( int j = 0; j < i; ++j )
			cap = max( cap, h[i] - h[j] );
	}
	return cap;
}

void BuyAndSellStockOnceTest()
{
#if TEST
	default_random_engine gen( ( random_device() )( ) );
	for ( int times = 0; times < 10; ++times ) {
		int n;
		uniform_int_distribution<int> dis( 1, 1000 );
		n = dis( gen );
		vector<double> A;
		uniform_real_distribution<double> dis2( 0, n );
		for ( int i = 0; i < n; ++i ) {
			A.emplace_back( dis2( gen ) );
		}
		cout << BuyAndSellStockOnce( A ) << endl;
		assert( BuyAndSellStockOnceCheckAns( A ) == BuyAndSellStockOnce( A ) );
	}
#endif
}

#pragma endregion Test
