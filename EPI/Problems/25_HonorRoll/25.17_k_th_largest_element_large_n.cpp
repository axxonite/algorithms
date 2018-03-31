// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

#define TEST 0

int FindKthLargestUnknownLength( istringstream* stream, int k )
{
	return -1;
}

#pragma region Test

static void SimpleTestArray( vector<int> A ) {
	stringstream ss;
	for ( int a : A ) {
		ss << a << ' ';
	}
	for ( int i = 0; i < A.size(); ++i ) {
		cout << "i = " << i << endl;
		istringstream stream( ss.str() );
		int k = i + 1;
		int result = FindKthLargestUnknownLength( &stream, k );
		nth_element( A.begin(), A.begin() + A.size() - k, A.end() );
		assert( result == A[A.size() - k] );
	}
}

static void FindKthLargestUnknownLengthSimpleTest()
{
	vector<int> A = { 5, 6, 2, 1, 3, 0, 4 };
	SimpleTestArray( A );
	A = { 5, -1, 2, 1, 3, 1, 4, 2 << 31 - 1, 5 };
	SimpleTestArray( A );
	default_random_engine gen( ( random_device() )( ) );
	int N = 1000;
	A = {};
	for ( int i = 0; i < N; ++i ) {
		uniform_int_distribution<int> dis( 0, 10 - 1 );
		A.emplace_back( dis( gen ) );
	}
	SimpleTestArray( A );
	A = {};
	for ( int i = 0; i < N; ++i ) {
		uniform_int_distribution<int> dis( 0, 100000000 - 1 );
		A.emplace_back( dis( gen ) );
	}
	SimpleTestArray( A );
}

void FindKthLargestUnknownLengthTest()
{
#if TEST
	FindKthLargestUnknownLengthSimpleTest();
	default_random_engine gen( ( random_device() )( ) );
	for ( int times = 0; times < 1000; ++times ) {
		int n, k;
		uniform_int_distribution<int> n_dis( 1, 100000 );
		n = n_dis( gen );
		uniform_int_distribution<int> k_dis( 1, n );
		k = k_dis( gen );
		vector<int> A;
		for ( int i = 0; i < n; ++i ) {
			uniform_int_distribution<int> dis( 0, 9999999 );
			A.emplace_back( dis( gen ) );
		}
		stringstream ss;
		for ( int a : A ) {
			ss << a << ' ';
		}
		istringstream stream( ss.str() );
		int result = FindKthLargestUnknownLength( &stream, k );
		nth_element( A.begin(), A.begin() + A.size() - k, A.end() );
		cout << result << endl << A[A.size() - k] << endl;
		assert( result == A[A.size() - k] );
	}
#endif
}

#pragma endregion
