// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

#define TEST 0

bool IsValidSudoku( const vector<vector<int>>& grid ) 
{
	return false;
}

#pragma region Test

void IsValidSudokuTest()
{
#if TEST
	vector<vector<int>> A( 9, vector<int>( 9, 0 ) );
	A[0] = { 0, 2, 6, 0, 0, 0, 8, 1, 0 };
	A[1] = { 3, 0, 0, 7, 0, 8, 0, 0, 6 };
	A[2] = { 4, 0, 0, 0, 5, 0, 0, 0, 7 };
	A[3] = { 0, 5, 0, 1, 0, 7, 0, 9, 0 };
	A[4] = { 0, 0, 3, 9, 0, 5, 1, 0, 0 };
	A[5] = { 0, 4, 0, 3, 0, 2, 0, 5, 0 };
	A[6] = { 1, 0, 0, 0, 3, 0, 0, 0, 2 };
	A[7] = { 5, 0, 0, 2, 0, 4, 0, 0, 9 };
	A[8] = { 0, 3, 8, 0, 0, 0, 4, 6, 0 };
	assert( IsValidSudoku( A ) );
	// There are two 3s.
	A[8] = { 3, 3, 8, 0, 0, 0, 4, 6, 0 };
	assert( !IsValidSudoku( A ) ); 
#endif
}

#pragma endregion
