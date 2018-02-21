// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

#define TEST 0

int DeleteDuplicates( vector<int>& a ) 
{
	return 0;
}

#pragma region Test

void CheckAns( const vector<int>& A, size_t n ) 
{
	for ( size_t i = 1; i < n; ++i )
		assert( A[i - 1] != A[i] );
}

void DeleteDuplicatesSmallTest()
{
	vector<int> A = { 2, 3, 5, 5, 7, 11, 11, 11, 13 };
	assert( 6 == DeleteDuplicates( A ) );
}

void DeleteDuplicatesTest()
{
#if TEST
	DeleteDuplicatesSmallTest();
	default_random_engine gen( ( random_device() )( ) );
	size_t n;
	uniform_int_distribution<size_t> dis_n( 0, 10000 );
	n = dis_n( gen );
	for ( int times = 0; times < 20; ++times ) 
	{
		uniform_int_distribution<int> A_dis( -1000, 1000 );
		vector<int> A;
		generate_n( back_inserter( A ), n, [&] { return A_dis( gen ); } );
		sort( A.begin(), A.end() );
		auto B( A );
		auto iter = unique( B.begin(), B.end() );
		auto size = DeleteDuplicates( A );
		assert( size == distance( B.begin(), iter ) );
		CheckAns( A, size );
		cout << size << endl;
	}
#endif
}

#pragma endregion Test
