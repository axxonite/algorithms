// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

#define TEST 0

bool IsPalindrome2(const string& s)
{
	return true;
}

#pragma region Test

void IsPalindromeTest()
{
#if TEST
	assert(IsPalindrome2("A man, a plan, a canal: Panama"));
	assert(!IsPalindrome2("race a car"));
	assert(IsPalindrome2("Able was I, ere I saw Elba!"));
	assert(!IsPalindrome2("Ray a Ray"));
	assert(IsPalindrome2(""));
#endif
}

#pragma endregion Test
