// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	int ComputeNumberOfWaysToXY(int x, int y, vector<vector<int>>& numberOfWays)
	{
		if (x == 0 && y == 0)
			return 1;

		if (numberOfWays[x][y] == 0)
		{
			int ways_top = x == 0 ? 0 : ComputeNumberOfWaysToXY(x - 1, y, numberOfWays);
			int ways_left = y == 0 ? 0 : ComputeNumberOfWaysToXY(x, y - 1, numberOfWays);
			numberOfWays[x][y] = ways_top + ways_left;
		}
		return numberOfWays[x][y];
	}

	int NumberOfWays(int n, int m)
	{
		vector<vector<int>> numberOfWays(n, vector<int>(m, 0));
		return ComputeNumberOfWaysToXY(n - 1, m - 1, numberOfWays);
	}	
}