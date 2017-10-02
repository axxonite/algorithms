// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

#define TEST 0

typedef enum
{
	SMALLER,
	EQUAL,
	LARGER
} Ordering;

Ordering Compare(double a, double b)
{
	// Uses normalization for precision problem.
	double diff = (a - b) / b;
	return diff < -numeric_limits<double>::epsilon() ? SMALLER : diff > numeric_limits<double>::epsilon() ? LARGER : EQUAL;
}

double SquareRoot(double x)
{
	return 0;
}

#pragma region Test

static void SquareRootFloatSimpleTest()
{
	assert(Compare(SquareRoot(1.0), sqrt(1.0) == EQUAL));
	assert(Compare(SquareRoot(2.0), sqrt(2.0) == EQUAL));
	assert(Compare(SquareRoot(0.001), sqrt(0.001) == EQUAL));
	assert(Compare(SquareRoot(0.5), sqrt(0.5) == EQUAL));
	assert(Compare(SquareRoot(100000000.001), sqrt(100000000.001) == EQUAL));
	assert(Compare(SquareRoot(1024.0), sqrt(1024.0) == EQUAL));
}

void SquareRootFloatTest()
{
#if TEST
	SquareRootFloatSimpleTest();
	default_random_engine gen((random_device())());
	for (int times = 0; times < 100000; ++times)
	{
		double x;
		uniform_real_distribution<double> dis(0.0, 100000000.0);
		x = dis(gen);
		double res[2];
		cout << "x is " << x << endl;
		cout << (res[0] = SquareRoot(x)) << ' ' << (res[1] = sqrt(x)) << endl;
		assert(Compare(res[0], res[1]) == EQUAL);
	}
#endif
}

#pragma endregion Test
