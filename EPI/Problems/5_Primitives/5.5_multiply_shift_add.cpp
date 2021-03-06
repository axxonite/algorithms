// Copyright (c) 2013 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

// #define TEST

unsigned Add(unsigned a, unsigned b)
{
	return a + b;
}

unsigned Multiply(unsigned x, unsigned y)
{
	return x * y;
}

#pragma region Test
void MultiplyShiftAddTest()
{
#ifdef TEST
	default_random_engine gen((random_device())());
	// Random test, only works if the product is not greater than 2^32 - 1.
	for (int i = 0; i < 100000; ++i) {
		uniform_int_distribution<int> dis(0, 65534);
		unsigned int x = dis(gen), y = dis(gen);
		unsigned int prod = Multiply(x, y);
		unsigned int add = Add(x, y);
		assert(prod == x * y);
		assert(add == x + y);
		//cout << "PASS: x = " << x << ", y = " << y << "; prod = " << prod
		//	<< endl;
	}
#endif
}
#pragma endregion Test
