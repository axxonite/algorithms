#pragma once

#include <vector>
#include <random>

using namespace std;

namespace Solutions
{
	inline void RandomSampling(int k, vector<int>& a)
	{
		default_random_engine seed((random_device())());
		for (int i = 0; i < k; ++i)
			// Generate a random index in [i, a.size() - 1].
			swap(a[i], a[uniform_int_distribution<int>{i, static_cast<int>(a.size()) - 1}(seed)]);
	}
}
