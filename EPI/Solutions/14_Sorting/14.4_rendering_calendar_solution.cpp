// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	struct Event
	{
		int start, finish;
	};

	struct Endpoint
	{
		int time;
		bool isStart;

		bool operator < (const Endpoint& other) const
		{
			// watch out for the comparator - the comparator will assert if a < b is false and a > b is false but they are not equal.

			// so... if we are starting an event here, and the other event isn't... we start the new event before ending the last one? Doesn't seem legit, really. The
			// problem didn't specify what to do with intervals, and I assumed them to be disjoint. I suppose the end time means it's still running for that time period.
			return time < other.time || (time == other.time && isStart && !other.isStart);
		}
	};

	int FindMaxSimultaneousEvents(const vector<Event>& a)
	{
		vector<Endpoint> endpoints;
		for (auto e : a)
		{
			endpoints.emplace_back(Endpoint{ e.start, true });
			endpoints.emplace_back(Endpoint{ e.finish, false });
		}
		sort(endpoints.begin(), endpoints.end());
		int maxHeight = 0, curHeight = 0;
		for (auto e : endpoints)
			maxHeight = max(maxHeight, curHeight += e.isStart ? 1 : -1);
		return maxHeight;
	}
}