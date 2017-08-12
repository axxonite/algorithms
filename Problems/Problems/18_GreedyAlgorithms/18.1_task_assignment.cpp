// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"
#define TEST 0

struct PairedTasks
{
	int task1, task2;
};

vector<PairedTasks> OptimumTaskAssignment(vector<int> taskDurations) 
{
	vector<PairedTasks> solution;
	return solution;
}

#pragma region Test

void OptimumTaskAssignmentTest() 
{
#if TEST
	default_random_engine gen((random_device())());
	int n;
	uniform_int_distribution<int> dis(1, 10000);
	n = dis(gen);
	vector<int> A;
	for (size_t i = 0; i < n; ++i) {
		uniform_int_distribution<int> dis(0, 999);
		A.emplace_back(dis(gen));
	}
	vector<PairedTasks> P(OptimumTaskAssignment(A));
	int max = numeric_limits<int>::min();
	for (size_t i = 0; i < P.size(); ++i) {
		if (P[i].task1 + P[i].task2 > max) {
			max = P[i].task1 + P[i].task2;
		}
	}
	cout << max << endl;
#endif
}

#pragma endregion Test