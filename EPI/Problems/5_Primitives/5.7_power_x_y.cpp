// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

// #define TEST

double Power(double x, int y)
{
  return 0;
}

#pragma region Test

// 0 means equal, -1 means smaller, and 1 means larger.
int Compare(double a, double b)
{
	// Uses normalization for precision problem.
	double diff = (a - b) / b;
	return diff < -1.0e-9 ? -1 : diff > 1.0e-9;
}

void PowerTest()
{
#ifdef TEST
	default_random_engine gen((random_device())());
	double x;
	int y;
	uniform_real_distribution<> dis_x(0.0, 10.0);
	uniform_int_distribution<> dis_y(-32, 32);
	for (int times = 0; times < 10000; ++times)
	{
		x = dis_x(gen);
		y = dis_y(gen);
		//cout << x << "^" << y << ": " << Power(x, y) << " " << pow(x, y)
		//	<< endl;
		assert(!Compare(Power(x, y), std::pow(x, y)));
	}
#endif
}

#pragma endregion Test
