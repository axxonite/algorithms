// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	struct PairedTasks
	{
		int task1, task2;
	};

	vector<PairedTasks> OptimumTaskAssignment(vector<int> task_durations)
	{
		sort(task_durations.begin(), task_durations.end()); // Sort the tasks.
		vector<PairedTasks> optimum_assignments;
		// Pair the longest tasks with the shortest tasks.
		for (int i = 0, j = int(task_durations.size() - 1); i < j; ++i , --j)
			optimum_assignments.emplace_back(PairedTasks{task_durations[i], task_durations[j]});
		return optimum_assignments;
	}
}
