// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	int ComputeXChooseY(int n, int k, vector<vector<int>>& xChooseY)
	{
		if (k == 0 || n == k)
			return 1;

		if (xChooseY[n][k] == 0)
		{
			int withoutY = ComputeXChooseY(n - 1, k, xChooseY);
			int withY = ComputeXChooseY(n - 1, k - 1, xChooseY);
			xChooseY[n][k] = withoutY + withY;
		}
		return xChooseY[n][k];
	}

	int ComputeBinomialCoefficient(int n, int k)
	{
		vector<vector<int>> xChooseY(n + 1, vector<int>(k + 1, 0));
		return ComputeXChooseY(n, k, xChooseY);
	}
}
