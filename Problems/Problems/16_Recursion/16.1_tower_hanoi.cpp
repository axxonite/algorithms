// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

#define TEST 0

static int numSteps = 0;// don't forget to update the number of steps as you compute the solution.
const int kNumPegs = 3;

void ComputeTowerHanoi(int ringCount)
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

	numSteps = 0;
	ComputeTowerHanoi(4);
	assert(15 == numSteps);

	numSteps = 0;
	ComputeTowerHanoi(1);
	assert(1 == numSteps);

	numSteps = 0;
	ComputeTowerHanoi(0);
	assert(0 == numSteps);

	numSteps = 0;
	ComputeTowerHanoi(10);
	assert(1023 == numSteps);
#endif
}

#pragma endregion Test
