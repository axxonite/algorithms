// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

// #define TEST

vector<int> ExamineBuildingsWithSunset(istringstream* sin)
{
  return {};
}

#pragma region Test

void ExamineBuildingsWithSunsetTest()
{
#ifdef TEST
	default_random_engine gen((random_device())());
	for (int times = 0; times < 100; ++times)
	{
		uniform_int_distribution<int> dis(1, 1000);
		int n = dis(gen);
		stringstream ss;
		vector<int> heights;
		for (int i = 0; i < n; ++i)
		{
			uniform_int_distribution<int> dis(1, 2 * n);
			int height = dis(gen);
			ss << height << ' ';
			heights.emplace_back(height);
		}
		istringstream sin(ss.str());
		auto res = ExamineBuildingsWithSunset(&sin);
		//cout << res[0] << ' ' << heights[res[0]] << endl;
		for (int i = 1; i < res.size(); ++i)
		{
			//cout << res[i] << ' ' << heights[res[i]] << endl;
			assert(heights[res[i - 1]] < heights[res[i]]);
		}
	}
#endif
}

#pragma endregion Test