// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

#define TEST 0

static int num_steps = 0;
const int kNumPegs = 3;

void ComputeTowerHanoi(int num_rings)
{
}

#pragma region Test

void ComputeTowerHanoiTest()
{
#if TEST
	int n;
	default_random_engine gen((random_device())());
	uniform_int_distribution<int> dis(1, 10);
	n = dis(gen);
	cout << "n = " << n << endl;
	ComputeTowerHanoi(n);

	num_steps = 0;
	ComputeTowerHanoi(4);
	assert(15 == num_steps);

	num_steps = 0;
	ComputeTowerHanoi(1);
	assert(1 == num_steps);

	num_steps = 0;
	ComputeTowerHanoi(0);
	assert(0 == num_steps);

	num_steps = 0;
	ComputeTowerHanoi(10);
	assert(1023 == num_steps);
#endif
}

#pragma endregion Test
