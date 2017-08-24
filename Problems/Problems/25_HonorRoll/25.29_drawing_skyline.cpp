// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

#define TEST 0

struct Rectangle;
typedef vector<Rectangle> Skyline;

struct Rectangle
{
	int left, right, height;
};

typedef vector<Rectangle> Skyline;

Skyline ComputeSkyline(const vector<Rectangle>& buildings)
{
	Skyline result;
	return result;
}

#pragma region Test

void CheckAnswer(const Skyline& ans)
{
	// Just check there is no overlap.
	for (int i = 0; i < ans.size(); ++i)
	{
		assert(ans[i].left <= ans[i].right);
		if (i > 0)
		{
			assert(ans[i - 1].right <= ans[i].left);
			assert(ans[i - 1].right != ans[i].left ||
				ans[i - 1].height != ans[i].height);
		}
	}
}

void ComputeSkylineTest()
{
#if TEST
	default_random_engine gen((random_device())());
	for (int times = 0; times < 20; ++times)
	{
		int n;
		uniform_int_distribution<int> dis(1, 5000);
		n = dis(gen);
		vector<Rectangle> A;
		for (int i = 0; i < n; ++i)
		{
			uniform_int_distribution<int> left_dis(0, 999);
			int left = left_dis(gen);
			uniform_int_distribution<int> right_dis(left, left + 200);
			int right = right_dis(gen);
			uniform_int_distribution<int> height_dis(0, 99);
			int height = height_dis(gen);
			A.emplace_back(Rectangle{left, right, height});
		}
		Skyline ans = ComputeSkyline(A);
		//cout << "n = " << n << endl;
		CheckAnswer(ans);
	}
#endif
}

#pragma endregion Test
