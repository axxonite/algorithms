// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

#define TEST 0

int NumberOfWaysToTop(int top, int maximum_step)
{
	return 0;
}

#pragma region Test

void NumberOfWaysToTopTest()
{
#if TEST
	assert(5 == NumberOfWaysToTop(4, 2));
	assert(1 == NumberOfWaysToTop(1, 2));
	assert(1 == NumberOfWaysToTop(0, 3));
	default_random_engine gen((random_device())());
	int n, k;
	uniform_int_distribution<int> dis(1, 20);
	n = dis(gen);
	uniform_int_distribution<int> k_dis(1, n);
	k = k_dis(gen);
	cout << "n = " << n << ", k = " << k << endl;
	cout << NumberOfWaysToTop(n, k) << endl;
#endif
}

#pragma endregion Test