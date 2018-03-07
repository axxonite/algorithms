// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

#define TEST 0

int SearchFirstOfK( const vector<int>& a, int k ) 
{
	return -1;
}

#pragma region Test

static void SearchFirstOfKSimpleTest()
{
	vector<int> A = { 0, 1, 2, 3, 4, 5, 6, 7 };
	assert( 0 == SearchFirstOfK( A, 0 ) );
	assert( 1 == SearchFirstOfK( A, 1 ) );
	assert( 4 == SearchFirstOfK( A, 4 ) );
	assert( 6 == SearchFirstOfK( A, 6 ) );
	assert( 7 == SearchFirstOfK( A, 7 ) );
	assert( -1 == SearchFirstOfK( A, 8 ) );
	assert( -1 == SearchFirstOfK( A, numeric_limits<int>::min() ) );
	A[0] = 1;
	assert( 0 == SearchFirstOfK( A, 1 ) );
	A[5] = 4;
	A[6] = 4;
	assert( 4 == SearchFirstOfK( A, 4 ) );
	A = { 1, 1, 1, 1, 1, 2 };
	assert( -1 == SearchFirstOfK( A, 0 ) );
	assert( 0 == SearchFirstOfK( A, 1 ) );
	assert( 5 == SearchFirstOfK( A, 2 ) );
	A[4] = 2;
	assert( 4 == SearchFirstOfK( A, 2 ) );
}

int SearchFirstOfKAlternative( const vector<int>& A, int k ) {
	auto result = lower_bound( A.begin(), A.end(), k );
	if ( *result == k )
		return distance( A.begin(), result );
	return -1;
}

void SearchFirstOfKTest()
{
#if TEST
	SearchFirstOfKSimpleTest();
	default_random_engine gen( ( random_device() )( ) );
	for ( int times = 0; times < 10; ++times ) 
	{
		int n;
		uniform_int_distribution<int> dis( 1, 100000 );
		n = dis( gen );
		vector<int> A;
		uniform_int_distribution<int> k_dis( 0, n - 1 );
		int k = k_dis( gen );
		for ( int i = 0; i < n; ++i ) 
		{
			uniform_int_distribution<int> dis( 0, n - 1 );
			A.emplace_back( dis( gen ) );
		}
		sort( A.begin(), A.end() );
		int ans = SearchFirstOfK( A, k );
		assert( SearchFirstOfKAlternative( A, k ) == ans );
		cout << "k = " << k << " locates at " << ans << endl;
		if ( ans != -1 ) 
			cout << "A[k] = " << A[ans] << endl;
		auto it = find( A.cbegin(), A.cend(), k );
		assert( ( it == A.cend() && ans == -1 ) || ( distance( A.cbegin(), it ) == ans ) );
	}
#endif
}

#pragma endregion