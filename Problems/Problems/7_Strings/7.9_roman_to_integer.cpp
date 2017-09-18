// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

#define TEST 0

int RomanToInteger(const string& s)
{
	return 0;
}
#pragma region Test

void RomanToIntegerTest()
{
#if TEST
	assert(7 == RomanToInteger("VII"));
	assert(184 == RomanToInteger("CLXXXIV"));
	assert(9 == RomanToInteger("IX"));
	assert(40 == RomanToInteger("XL"));
	assert(60 == RomanToInteger("LX"));
	assert(1500 == RomanToInteger("MD"));
	assert(400 == RomanToInteger("CD"));
	assert(1900 == RomanToInteger("MCM"));
	assert(9919 == RomanToInteger("MMMMMMMMMCMXIX"));
#endif
}

#pragma endregion Test
