// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

#define TEST 0

int EvalRPN( const string& RPN_expression ) 
{
	return 0;
}

#pragma region Test

void EvalRPNTest()
{
#if TEST
	assert( 0 == EvalRPN( "2,-10,/" ) );
	assert( -5 == EvalRPN( "-10,2,/" ) );
	assert( 5 == EvalRPN( "-10,-2,/" ) );
	assert( -5 == EvalRPN( "5,10,-" ) );
	assert( 6 == EvalRPN( "-10,-16,-" ) );
	assert( 12 == EvalRPN( "10,2,+" ) );
	assert( 15 == EvalRPN( "1,2,+,3,4,*,+" ) );
	assert( 42 == EvalRPN( "1,2,3,4,5,+,*,+,+,3,4,*,+" ) );
	assert( -6 == EvalRPN( "1,2,3,4,5,+,*,+,+,3,4,*,+,-7,/" ) );
#endif
}

#pragma endregion