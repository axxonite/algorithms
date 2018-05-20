// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	int ComputeXChooseY(int n, int k, vector<vector<int>>& xChooseY)
	{
		// there is only one key way to choose an a size-0 subset: the empty subset.
		// there is only one subset of size n when we have n elements.
		if (k == 0 || n == k)
			return 1;

		if (xChooseY[n][k] == 0)
		{
			// Consider element x. We can either add the element x to the subset and form a k-1 size subset from the remaining elements.
			// Or we NOT add the element X, and form a k-size subset from the remaining elements.
			// In both cases we do not have to consider the element x any further, hence the size of our set (n) is reduced by one.
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
