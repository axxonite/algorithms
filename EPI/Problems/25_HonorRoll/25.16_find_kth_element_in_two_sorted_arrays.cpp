// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

// #define TEST

int FindKthInTwoSortedArrays( const vector<int>& a, const vector<int>& b, int k ) 
{
  return 0;
}

#pragma region Test

template <typename T>
T FindKthInTwoSortedArraysCheckAnswer( const vector<T>& A, const vector<T>& B, int k )
{
	int i = 0, j = 0, count = 0;
	T ret;
	while ( ( i < A.size() || j < B.size() ) && count < k ) {
		if ( i < A.size() && j < B.size() ) {
			if ( A[i] < B[j] ) {
				ret = A[i];
				++i;
			}
			else {
				ret = B[j];
				++j;
			}
		}
		else if ( i < A.size() ) {
			ret = A[i];
			++i;
		}
		else {
			ret = B[j];
			++j;
		}
		++count;
	}
	return ret;
}

void FindKthInTwoSortedArraysSmallTest() {
	// AA: handwritten test
	vector<int> A0 = { 0, 1, 2, 3 };
	vector<int> B0 = { 0, 1, 2, 3 };
	assert( 0 == FindKthInTwoSortedArrays( A0, B0, 1 ) );
	assert( 0 == FindKthInTwoSortedArrays( A0, B0, 2 ) );
	assert( 1 == FindKthInTwoSortedArrays( A0, B0, 3 ) );
	assert( 1 == FindKthInTwoSortedArrays( A0, B0, 4 ) );
	assert( 2 == FindKthInTwoSortedArrays( A0, B0, 5 ) );
}

void FindKthInTwoSortedArraysTest()
{
#ifdef TEST
	FindKthInTwoSortedArraysSmallTest();
	default_random_engine gen( ( random_device() )( ) );
	// Random test 10000 times.
	for ( int times = 0; times < 100; ++times ) {
		vector<int> A, B;
		int n, m, k;
		uniform_int_distribution<int> dis( 1, 10000 );
		n = dis( gen ), m = dis( gen );
		uniform_int_distribution<int> k_dis( 1, n + m );
		k = k_dis( gen );
		uniform_int_distribution<int> dis2( 0, 99999 );
		for ( size_t i = 0; i < n; ++i ) {
			A.emplace_back( dis2( gen ) );
		}
		for ( size_t i = 0; i < m; ++i ) {
			B.emplace_back( dis2( gen ) );
		}
		sort( A.begin(), A.end() ), sort( B.begin(), B.end() );
		/*
		for (int i = 0; i < A.size(); ++i) {
		cout << A[i] << ' ';
		}
		cout << endl;
		for (int j = 0; j < B.size(); ++j) {
		cout << B[j] << ' ';
		}
		cout << endl;
		*/
		int ans = FindKthInTwoSortedArrays( A, B, k );
		cout << k << "th = " << ans << endl;
		assert( ans == FindKthInTwoSortedArraysCheckAnswer( A, B, k ) );
	}
#endif
}

#pragma endregion
