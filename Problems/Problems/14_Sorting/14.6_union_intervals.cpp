// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

#define TEST 1

struct Interval
{
private:
	struct Endpoint
	{
		bool isClosed; // Closed means that it includes the boundary.
		int val;
	};

public:

	Endpoint l, r;
};

vector<Interval> UnionOfIntervals(vector<Interval> intervals)
{
	vector<Interval> result;
	return result;
}

#pragma region Test

void CheckIntervals(const vector<Interval>& A)
{
	// Only check the intervals do not overlap with each other.
	for (size_t i = 1; i < A.size(); ++i)
		assert(A[i - 1].r.val < A[i].l.val || (A[i - 1].r.val == A[i].l.val && !A[i - 1].r.isClosed && !A[i].l.isClosed));
}

void UnionOfIntervalsTest()
{
#if TEST
	default_random_engine gen((random_device())());
	for (int times = 0; times < 1000; ++times)
	{
		uniform_int_distribution<int> dis(1, 1000);
		int n = dis(gen);
		vector<Interval> A;
		for (int i = 0; i < n; ++i)
		{
			Interval temp;
			uniform_int_distribution<int> zero_or_one(0, 1);
			uniform_int_distribution<int> dis1(0, 9999);
			temp.l.isClosed = zero_or_one(gen) , temp.l.val = dis1(gen);
			uniform_int_distribution<int> dis2(temp.l.val + 1, temp.l.val + 100);
			temp.r.isClosed = zero_or_one(gen) , temp.r.val = dis2(gen);
			A.emplace_back(temp);
		}
		vector<Interval> ret = UnionOfIntervals(A);
		if (!ret.empty())
			CheckIntervals(ret);
	}
#endif
}

#pragma endregion Test