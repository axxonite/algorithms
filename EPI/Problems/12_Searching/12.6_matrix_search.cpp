// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

#define TEST 0

bool MatrixSearch( const vector<vector<int>>& a, int x )
{
	return false;
}

#pragma region Test

static void MatrixSearchSimpleTest()
{
	vector<vector<int>> A = { { 1 } };
	assert( !MatrixSearch( A, 0 ) );
	assert( MatrixSearch( A, 1 ) );

	A = { { 1, 5 },{ 2, 6 } };
	assert( !MatrixSearch( A, 0 ) );
	assert( MatrixSearch( A, 1 ) );
	assert( MatrixSearch( A, 2 ) );
	assert( MatrixSearch( A, 5 ) );
	assert( MatrixSearch( A, 6 ) );
	assert( !MatrixSearch( A, 3 ) );
	assert( !MatrixSearch( A, numeric_limits<int>::max() ) );

	A = { { 2, 5 },{ 2, 6 } };
	assert( !MatrixSearch( A, 1 ) );
	assert( MatrixSearch( A, 2 ) );

	A = { { 1, 5, 7 },{ 3, 10, 100 },{ 3, 12, numeric_limits<int>::max() } };
	assert( MatrixSearch( A, 1 ) );
	assert( !MatrixSearch( A, 2 ) );
	assert( !MatrixSearch( A, 4 ) );
	assert( MatrixSearch( A, 3 ) );
	assert( MatrixSearch( A, 10 ) );
	assert( MatrixSearch( A, numeric_limits<int>::max() ) );
	assert( !MatrixSearch( A, numeric_limits<int>::max() - 1 ) );
	assert( MatrixSearch( A, 12 ) );
}

// O(n^2) solution for verifying answer.
bool BruteForceSearch( const vector<vector<int>>& A, int x ) 
{
	for ( int i = 0; i < A.size(); ++i ) 
	{
		for ( int j = 0; j < A[i].size(); ++j ) 
		{
			if ( A[i][j] == x ) 
				return true;
		}
	}
	return false;
}

void MatrixSearchTest()
{
#if TEST
	MatrixSearchSimpleTest();
	default_random_engine gen( ( random_device() )( ) );
	for ( int times = 0; times < 100; ++times ) {
		int n, m;
		uniform_int_distribution<int> dis( 1, 100 );
		n = dis( gen ), m = dis( gen );
		vector<vector<int>> A( n, vector<int>( m ) );
		uniform_int_distribution<int> dis2( 0, 99 );
		A[0][0] = dis2( gen );
		for ( int i = 0; i < n; ++i ) 
		{
			for ( int j = 0; j < m; ++j ) 
			{
				int up = ( i == 0 ) ? 0 : A[i - 1][j];
				int left = ( j == 0 ) ? 0 : A[i][j - 1];
				uniform_int_distribution<int> shift_dis( 1, 20 );
				A[i][j] = max( up, left ) + shift_dis( gen );
			}
		}
		uniform_int_distribution<int> x_dis( 0, 999 );
		int x = x_dis( gen );
		assert( BruteForceSearch( A, x ) == MatrixSearch( A, x ) );
	}
#endif
}

#pragma endregion
