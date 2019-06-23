// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

// #define TEST

int MinimumTotalWaitingTime(vector<int> t)
{
	return 0;
}

#pragma region Test

void SmallTestMinWaitingTime() { assert(10 == MinimumTotalWaitingTime({ 5, 1, 2, 3 })); }

void MinimumTotalWaitingTimeTest()
{
#ifdef TEST
	SmallTestMinWaitingTime();
	default_random_engine gen((random_device())());
	int n;
	uniform_int_distribution<int> dis(1, 100);
	n = dis(gen);
	vector<int> waiting_time;
	for (int i = 0; i < n; ++i) {
		uniform_int_distribution<int> dis(0, 999);
		waiting_time.push_back(dis(gen));
	}
	//for (int i = 0; i < n; ++i) {
	//	cout << waiting_time[i] << ' ';
	//}
	//cout << endl;
	//cout << MinimumTotalWaitingTime(waiting_time) << endl;
#endif
}

#pragma endregion