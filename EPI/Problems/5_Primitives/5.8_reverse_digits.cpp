// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

// #define TEST

int ReverseDigits(int x)
{
	return 0;
}

#pragma region Test


void ReverseDigitsTest()
{
#ifdef TEST
	auto reversed = ReverseDigits(42);
	assert(reversed == 24);
	reversed = ReverseDigits(-314);
	assert(reversed == -413);
#endif
}

#pragma endregion 