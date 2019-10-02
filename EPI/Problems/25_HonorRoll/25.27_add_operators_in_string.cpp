// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

// #define TEST

bool ExpressionSynthesis( const vector<int>& digits, int target ) 
{
  return false;
}

#pragma region Test

void ExpressionSynthesisTest()
{
#ifdef TEST
	vector<int> A = { 2, 3, 4 };
	int k = 4;
	assert( !ExpressionSynthesis( A, k ) );
	A = { 1, 2, 3, 4 };
	k = 11;
	assert( ExpressionSynthesis( A, k ) );
	A = { 1, 2, 3, 2, 5, 3, 7, 8, 5, 9 };
	k = 995;
	assert( ExpressionSynthesis( A, k ) );
	A = { 5, 2, 3, 4, 1 };
	k = 20;
	assert( ExpressionSynthesis( A, k ) );
	A = { 1, 1, 2, 3 };
	k = 124;
	assert( ExpressionSynthesis( A, k ) );
#endif
}

#pragma endregion
