// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	int MinimumTotalWaitingTime(vector<int> service_times)
	{
		// Sort the service times in increasing order.
		sort(service_times.begin(), service_times.end());

		int total_waiting_time = 0;
		for (int i = 0; i < service_times.size(); ++i)
		{
			int num_remaining_queries = int(service_times.size()) - i - 1;
			total_waiting_time += service_times[i] * num_remaining_queries; // All the remaining queries must wait for the duration of the service time of the current query.
		}
		return total_waiting_time;
	}
}
