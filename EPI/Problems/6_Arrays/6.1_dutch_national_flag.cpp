// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

#define TEST 0

typedef enum
{
	RED,
	WHITE,
	BLUE
} Color;

void DutchFlagPartition(int pivot, vector<Color>& a)
{
}

#pragma region Test

vector<Color> RandVectorDutchFlag(int len)
{
	default_random_engine gen((random_device())());
	vector<Color> ret;
	while (len--)
	{
		uniform_int_distribution<int> dis(0, 2);
		ret.push_back(static_cast<Color>(dis(gen)));
	}
	return ret;
}

void DutchFlagPartitionTest()
{
#if TEST
	default_random_engine gen((random_device())());
	for (int times = 0; times < 1000; ++times)
	{
		uniform_int_distribution<int> dis(1, 100);
		int n = dis(gen);
		vector<Color> A(RandVectorDutchFlag(n));
		uniform_int_distribution<int> dis2(0, A.size() - 1);
		int pivot_index = dis2(gen);
		Color pivot = A[pivot_index];
		DutchFlagPartition(pivot_index, A);
		int i = 0;
		while (i < A.size() && A[i] < pivot)
		{
			//cout << A[i] << ' ';
			++i;
		}
		while (i < A.size() && A[i] == pivot)
		{
			//cout << A[i] << ' ';
			++i;
		}
		while (i < A.size() && A[i] > pivot)
		{
			//cout << A[i] << ' ';
			++i;
		}
		cout << endl;
		assert(i == A.size());
	}
#endif
}

#pragma endregion Test
