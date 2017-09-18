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
			++seenSoFar;
			// Generate a random number in [0, num_seen_so_far - 1], and if this number is in [0, k - 1], we replace that element from the sample with x.
			const int idx_to_replace = uniform_int_distribution<int>{ 0, seenSoFar - 1 }(seed);
			if (idx_to_replace < k)
				runningSample[idx_to_replace] = x;
		}
		return runningSample;
	}
}
