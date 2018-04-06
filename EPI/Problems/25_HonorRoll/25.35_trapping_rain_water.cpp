// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

#define TEST 0

int CalculateTrappingWater( const vector<int> &heights )
{
	return -1;
}

#pragma region Test

// Stack approach, O(n) time, O(n) space
int CalculateTrappingWaterCheckAnswer( const vector<int> &A ) {
	struct HeightBound {
		int left_bound, right_bound;
	};

	stack<HeightBound> s;
	int sum = 0;
	for ( int i = 0; i < A.size(); ++i ) {
		while ( !s.empty() && s.top().right_bound <= A[i] ) {
			int bottom = s.top().right_bound;
			s.pop();
			if ( s.empty() ) {
				break;
			}
			int top = min( s.top().right_bound, A[i] );
			sum += ( top - bottom ) * ( i - s.top().left_bound - 1 );
		}
		s.emplace( HeightBound{ i, A[i] } );
	}
	return sum;
}

void CalculateTrappingWaterSmallTest() {
	vector<int> A = { 1, 0, 3, 2, 5, 0, 1 };
	assert( CalculateTrappingWater( A ) == 3 );
	A = { 1, 2, 1, 3, 4, 4, 5, 6, 2, 1, 3, 1, 3, 2, 1, 2, 4, 1 };
	assert( CalculateTrappingWater( A ) == 18 );
}


void CalculateTrappingWaterTest()
{
#if TEST
	CalculateTrappingWaterSmallTest();
	default_random_engine gen( ( random_device() )( ) );
	for ( int times = 0; times < 10000; ++times ) {
		int n;
		uniform_int_distribution<int> n_dis( 1, 1000 );
		n = n_dis( gen );
		vector<int> A;
		uniform_int_distribution<int> A_dis( 0, 10 );
		generate_n( back_inserter( A ), n, [&] { return A_dis( gen ); } );
		copy( A.cbegin(), A.cend(), ostream_iterator<int>( cout, " " ) );
		cout << endl;
		cout << CalculateTrappingWaterCheckAnswer( A ) << " " << CalculateTrappingWater( A ) << endl;
		assert( CalculateTrappingWaterCheckAnswer( A ) == CalculateTrappingWater( A ) );
	}
#endif
}

#pragma endregion
