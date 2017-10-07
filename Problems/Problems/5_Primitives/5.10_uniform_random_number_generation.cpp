// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

#define TEST 0

int ZeroOneRandom()
{
	default_random_engine gen((random_device())());
	uniform_int_distribution<int> dis(0, 1);
	return dis(gen);
}

int UniformRandom(int low, int high)
{
	return 0;
}

#pragma region Test

void UniformRandomTest()
{
#if TEST
	default_random_engine gen((random_device())());
	for (int times = 0; times < 1000; ++times)
	{
		int a, b;
		uniform_int_distribution<int> a_dis(0, 99);
		a = a_dis(gen);
		uniform_int_distribution<int> b_dis(a + 1, a + 100);
		b = b_dis(gen);
		int x = UniformRandom(a, b);
		cout << "a = " << a << " b = " << b << endl;
		cout << "random result = " << x << endl;
		assert(x >= a && x <= b);
	}
#endif
}

#pragma endregion Test
