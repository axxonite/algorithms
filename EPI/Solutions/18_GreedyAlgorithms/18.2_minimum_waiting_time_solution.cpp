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
			// This seems wrong. If I have 5 queries, then on the first iteration we should have all FIVE queries waiting for that amount of time, not four as specified here.
			// Perhaps the book meant, what is the waiting time before the query *starts*, not ends.
			int num_remaining_queries = int(service_times.size()) - i - 1;
			total_waiting_time += service_times[i] * num_remaining_queries; // All the remaining queries must wait for the duration of the service time of the current query.
		}
		return total_waiting_time;
	}
}
