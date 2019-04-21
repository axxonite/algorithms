// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

#define TEST 0

int EuclidGCD(int a, int b)
{
	return 0;
}

#pragma region Test

void EuclidGCDTest()
{
#if TEST
	assert(EuclidGCD(30, 21) == 3);
	assert(EuclidGCD(99, 78) == 3);
#endif
}

#pragma endregion