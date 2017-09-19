// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	vector<int> OnlineRandomSample(istringstream* sin, int k)
	{
		int x;
		vector<int> runningSample;
		// Stores the first k elements.
		for (int i = 0; i < k && *sin >> x; ++i)
			runningSample.emplace_back(x);

		default_random_engine seed((random_device())()); // Random num generator.
		// Have read the first k elements.
		int seenSoFar = k;
		while (*sin >> x)
		{
			const int toReplace = uniform_int_distribution<int>{ 0, seenSoFar}(seed);
			if (toReplace < k)
				runningSample[toReplace] = x;
			++seenSoFar;
		}
		return runningSample;
	}
}
