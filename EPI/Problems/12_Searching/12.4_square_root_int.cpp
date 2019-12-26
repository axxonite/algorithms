// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

// #define TEST

int SquareRoot(int k)
{
	return 0;
}

#pragma region Test

static void SquareRootSimpleTest()
{
	assert(SquareRoot(0) == 0);
	assert(SquareRoot(1) == 1);
	assert(SquareRoot(2) == 1);
	assert(SquareRoot(3) == 1);
	assert(SquareRoot(4) == 2);
	assert(SquareRoot(7) == 2);
	assert(SquareRoot(121) == 11);
	assert(SquareRoot(64) == 8);
	assert(SquareRoot(300) == 17);
	assert(SquareRoot(numeric_limits<int>::max()) == 46340);
}

void SquareRootTest()
{
#ifdef TEST
	SquareRootSimpleTest();
	int x;
	default_random_engine gen((random_device())());
	uniform_int_distribution<int> dis(0, numeric_limits<int>::max());
	for (int times = 0; times < 100; ++times)
	{
		x = dis(gen);
		int result[2];
		//cout << "x is " << x << endl;
		//cout << (result[0] = SquareRoot(x)) << ' '
		//	<< (result[1] = static_cast<int>(sqrt(x))) << endl;
		assert(result[0] == result[1]);
	}
#endif
}

#pragma endregion Test
