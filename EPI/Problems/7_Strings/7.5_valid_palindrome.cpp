// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

#define TEST 0

bool IsPalindrome( const string& s )
{
	return false;
}
#pragma region Test

void IsPalindromeTest()
{
#if TEST
	assert( IsPalindrome( "A man, a plan, a canal: Panama" ) );
	assert( !IsPalindrome( "race a car" ) );
	assert( IsPalindrome( "Able was I, ere I saw Elba!" ) );
	assert( !IsPalindrome( "Ray a Ray" ) );
	assert( IsPalindrome( "" ) );
#endif
}

#pragma endregion