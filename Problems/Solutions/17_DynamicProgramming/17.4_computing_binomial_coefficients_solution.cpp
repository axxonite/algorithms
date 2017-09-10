// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	int ComputeXChooseY(int x, int y, vector<vector<int>>& xChooseY)
	{
		if (y == 0 || x == y)
			return 1;

		if (xChooseY[x][y] == 0)
		{
			int withoutY = ComputeXChooseY(x - 1, y, xChooseY);
			int withY = ComputeXChooseY(x - 1, y - 1, xChooseY);
			xChooseY[x][y] = withoutY + withY;
		}
		return xChooseY[x][y];
	}

	int ComputeBinomialCoefficient(int n, int k)
	{
		vector<vector<int>> xChooseY(n + 1, vector<int>(k + 1, 0));
		return ComputeXChooseY(n, k, xChooseY);
	}
}
