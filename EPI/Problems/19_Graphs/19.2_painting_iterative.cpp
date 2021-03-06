// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

// #define TEST

// the matrix is in [x][y] order.
void FlipColor( int x, int y, vector<deque<bool>>& a ) 
{
}

#pragma region Test

void PrintMatrix( const vector<deque<bool>>& A ) 
{
	for (const auto& i : A)
  {
		for (bool j : i)
      cout << j << ' ';
		cout << endl;
	}
}

// this doesn't really test that the colors were flipped.
void FlipColorTest()
{
#ifdef TEST
  default_random_engine gen( ( random_device() )( ) );
	uniform_int_distribution<size_t> dis( 1, 100 );
	size_t n = dis(gen);
	vector<deque<bool>> A( n, deque<bool>( n ) );
	for ( size_t i = 0; i < n; ++i ) 
	{
		for ( size_t j = 0; j < n; ++j ) 
		{
			uniform_int_distribution<int> zero_or_one( 0, 1 );
			A[i][j] = zero_or_one( gen );
		}
	}
	uniform_int_distribution<size_t> dis2( 0, n - 1 );
	size_t i = dis2( gen ), j = dis2( gen );
	cout << "color = " << i << ' ' << j << ' ' << A[i][j] << endl;
	PrintMatrix( A );
	FlipColor( static_cast<int>( i ), static_cast<int>( j ), A );
	cout << endl;
	PrintMatrix( A );
#endif
}

#pragma endregion
