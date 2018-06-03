// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

#define TEST 0

// Note the matrix is in row-column order.
vector<int> MatrixInSpiralOrder( vector<vector<int>> matrix )
{
	vector<int> result;
	return result;
}

#pragma region Test

void MatrixInSpiralOrderSimpleTest() {
	vector<vector<int>> A = { { 1, 2, 3 },{ 4, 5, 6 },{ 7, 8, 9 } };
	auto result = MatrixInSpiralOrder( A );
	vector<int> golden_result = { 1, 2, 3, 6, 9, 8, 7, 4, 5 };
	assert( equal( result.begin(), result.end(), golden_result.begin(),
		golden_result.end() ) );
}

void MatrixInSpiralOrderTest()
{
#if TEST
	MatrixInSpiralOrderSimpleTest();
	default_random_engine gen( ( random_device() )( ) );
	int N;
	uniform_int_distribution<int> dis( 1, 50 );
	N = dis( gen );
	vector<vector<int>> A( N, vector<int>( N ) );
	int x = 1;
	for ( size_t i = 0; i < N; ++i ) {
		for ( size_t j = 0; j < N; ++j ) {
			A[i][j] = x++;
		}
	}
	auto result = MatrixInSpiralOrder( A );
	copy( result.begin(), result.end(), ostream_iterator<int>( cout, " " ) );
	cout << endl;
#endif
}

#pragma endregion
