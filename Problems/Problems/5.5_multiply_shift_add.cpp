// Copyright (c) 2013 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"
#include <cassert>
#include <iostream>
#include <random>
#include <string>

using namespace std;

unsigned Add(unsigned a, unsigned b)
{
	return 0;
}

unsigned Multiply(unsigned x, unsigned y)
{
	return 0;
}


#pragma region Test
void MultiplyShiftAddTest() {
	default_random_engine gen((random_device())());
	// Random test, only works if the product is not greater than 2^32 - 1.
	for (int i = 0; i < 100000; ++i) {
		uniform_int_distribution<int> dis(0, 65534);
		unsigned int x = dis(gen), y = dis(gen);
		unsigned int prod = Multiply(x, y);
		assert(prod == x * y);
		cout << "PASS: x = " << x << ", y = " << y << "; prod = " << prod
			<< endl;
	}
}
#pragma endregion Test