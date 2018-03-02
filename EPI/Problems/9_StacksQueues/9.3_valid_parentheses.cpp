// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

#define TEST 0

bool IsWellFormed( const string& s ) 
{
	return false;
}

#pragma region Test

void IsWellFormedSmallTest() 
{
	assert( IsWellFormed( "()" ) );
	assert( IsWellFormed( "()[]{}" ) );
	assert( IsWellFormed( "[()[]]{}" ) );
	assert( IsWellFormed( "(()[]{()[]{}{}})" ) );
	assert( !IsWellFormed( "([)]" ) );
	assert( !IsWellFormed( "[" ) );
	assert( !IsWellFormed( "(()[]{()[]{})({}})" ) );
}

void IsWellFormedTest()
{
#if TEST
	IsWellFormedSmallTest();
#endif
}

#pragma endregion
