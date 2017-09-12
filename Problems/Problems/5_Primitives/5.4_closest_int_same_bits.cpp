// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

#define TEST 0

unsigned long ClosestIntSameBitCount(unsigned long x)
{
	return 0;
}

#pragma region Test

int CountBitsSetTo1(unsigned long x)
{
	int count = 0;
	while (x)
	{
		x &= (x - 1);
		++count;
	}
	return count;
}

void ClosestIntSameBitCountSmallTest()
{
	assert(ClosestIntSameBitCount(6) == 5);
	assert(ClosestIntSameBitCount(7) == 11);
	assert(ClosestIntSameBitCount(2) == 1);
	assert(ClosestIntSameBitCount(32) == 16);
	assert(ClosestIntSameBitCount(numeric_limits<unsigned long>::max() - 1) == numeric_limits<unsigned long>::max() - 2);
	try
	{
		ClosestIntSameBitCount(numeric_limits<unsigned long>::max());
		assert(false);
	}
	catch (const exception& e)
	{
		cout << e.what() << endl;
	}
	try
	{
		ClosestIntSameBitCount(0);
		assert(false);
	}
	catch (const exception& e)
	{
		cout << e.what() << endl;
	}
}

void ClosestIntSameBitCountTest()
{
#if TEST
	ClosestIntSameBitCountSmallTest();
	default_random_engine gen((random_device())());
	unsigned long x;
	uniform_int_distribution<unsigned long> dis(0, numeric_limits<unsigned long>::max());
	x = dis(gen);
	try
	{
		unsigned long res = ClosestIntSameBitCount(x);
		cout << x << ' ' << res << endl;
		assert(CountBitsSetTo1(x) == CountBitsSetTo1(res));
	}
	catch (const exception& e)
	{
		cout << x << ' ' << e.what() << endl;
	}
#endif
}

#pragma endregion Test
