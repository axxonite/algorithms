// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

#define TEST 0

int FindElementAppearsOnce( const vector<int> &A )
{
	return -1;
}

#pragma region Test

int FindElementAppearsOnceAlternative( const vector<int> &A ) 
{
	// ones denotes whether a bit-position has been set once (modulo 3) so far.
	// twos denotes whether a bit-position has been set twice (modulo 3) so far.
	int ones = 0, twos = 0;
	int next_ones, next_twos;
	for ( const int &i : A ) {
		// After reading A[i], bit-position j has a count of 1 modulo 3
		// if it had a count of 1 modulo 3 (the j-th bit in ones is set)
		// and the j-th bit in A[i] is 0 or the count was 0 modulo 3
		// (the j-th bit is not set in ones and in not set in twos) and
		// the j-th bit in A[i] is 1.
		next_ones = ( ~i & ones ) | ( i & ~ones & ~twos );

		// After reading A[i], bit-position j has a count of 2 modulo 3
		// if it had a count of 2 modulo 3 (the j-th bit in twos is set)
		// and the j-th bit in A[i] is a 0 or the count was 1 modulo 3
		// (the j-th bit is set in ones) and the j-th bit in A[i] is a 1.
		next_twos = ( ~i & twos ) | ( i & ones );

		ones = next_ones, twos = next_twos;
	}
	// Since ones denotes bit-positions which have been set once (modulo 3),
	// it is the element which appears only once.
	return ones;
}

void FindElementAppearsOnceTest2() {
	vector<int> A = { -2, -2, 1, 1, -3, 1, -3, -3, -4, -2 };
	assert( FindElementAppearsOnce( A ) == -4 );
	assert( FindElementAppearsOnceAlternative( A ) == -4 );
}

void FindElementAppearsOnceTest()
{
#if TEST
	default_random_engine gen( ( random_device() )( ) );
	for ( int times = 0; times < 10000; ++times ) {
		vector<int> A;
		int n;
		uniform_int_distribution<int> n_dis( 1, 10000 );
		n = n_dis( gen );
		uniform_int_distribution<int> dis( -n, n - 1 );
		int single = dis( gen );
		for ( int i = -n; i < n; ++i ) {
			A.emplace_back( i );
			if ( i != single ) {
				A.emplace_back( i );
				A.emplace_back( i );
			}
		}
		cout << "Singleton element: " << FindElementAppearsOnce( A ) << endl;
		assert( FindElementAppearsOnce( A ) == single );
		assert( FindElementAppearsOnceAlternative( A ) == single );
	}
#endif
}

#pragma endregion
