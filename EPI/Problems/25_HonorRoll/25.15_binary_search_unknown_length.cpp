// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

#define TEST 0

int BinarySearchUnknownLength( const vector<int>& a, int k )
{
	return -1;
}

#pragma region Test

void BinarySearchUnknownLengthSmallTest() {
	vector<int> A = { 1, 2, 3 };
	assert( BinarySearchUnknownLength( A, 3 ) == 2 );
	assert( BinarySearchUnknownLength( A, 1 ) == 0 );
	assert( BinarySearchUnknownLength( A, 2 ) == 1 );
	assert( BinarySearchUnknownLength( A, 4 ) == -1 );
	assert( BinarySearchUnknownLength( A, -1 ) == -1 );
}

void BinarySearchUnknownLengthTest()
{
#if TEST
	BinarySearchUnknownLengthSmallTest();
	int n, k;
	default_random_engine gen( ( random_device() )( ) );
	for ( int times = 0; times < 10; ++times ) {
		uniform_int_distribution<int> n_dis( 1, 1000000 );
		n = n_dis( gen );
		uniform_int_distribution<int> k_dis( 0, ( n * 2 ) - 1 );
		k = k_dis( gen );
		vector<int> A;
		for ( int i = 0; i < n; ++i ) {
			uniform_int_distribution<int> k_dis( 0, ( n * 2 ) - 1 );
			A.emplace_back( k_dis( gen ) );
		}
		sort( A.begin(), A.end() );
		cout << n << ' ' << k << endl;
		int idx = BinarySearchUnknownLength( A, k );
		cout << idx << endl;
		assert( ( idx == -1 && !binary_search( A.cbegin(), A.cend(), k ) ) ||
			A[idx] == k );
	}
#endif
}

#pragma endregion
