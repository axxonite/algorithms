// Copyright (c) 2013 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

// #define TEST

unsigned Divide(unsigned x, unsigned y)
{
	unsigned result = 0;
	return result;
}

#pragma region Test

void DivisionSimpleTest()
{
	assert(Divide(64, 1) == 64);
	assert(Divide(64, 2) == 32);
	assert(Divide(64, 3) == 21);
	assert(Divide(64, 4) == 16);
	assert(Divide(64, 5) == 12);
	assert(Divide(65, 2) == 32);
	assert(Divide(2600540749, 2590366779) == 1);
}

void DivideTest()
{
#ifdef TEST
	DivisionSimpleTest();
	default_random_engine gen((random_device())());
	uniform_int_distribution<size_t> dis(0, numeric_limits<size_t>::max());
	for (int times = 0; times < 100000; ++times)
	{
		unsigned x = dis(gen), y = dis(gen);
		y = (y == 0) ? 1 : y; // ensure no divide by 0.
		//cout << "times = " << times << ", x = " << x << ", y = " << y << endl;
		//cout << "first = " << x / y << ", second = " << Divide(x, y) << endl;
		assert(x / y == Divide(x, y));
	}
#endif
}
#pragma endregion Test
