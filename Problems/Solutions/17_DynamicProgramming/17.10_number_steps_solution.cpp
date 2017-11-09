// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	int ComputeNumberOfWaysToH(int h, int maximum_step, vector<int>& numberOfWaysToH)
	{
		if (h <= 1)
			return 1;

		if (numberOfWaysToH[h] == 0)
			for (int i = 1; i <= maximum_step && h - i >= 0; ++i)
				numberOfWaysToH[h] += ComputeNumberOfWaysToH(h - i, maximum_step, numberOfWaysToH);

		return numberOfWaysToH[h];
	}

	int NumberOfWaysToTop(int top, int maximum_step)
	{
		vector<int> numberOfWaysToH(top + 1, 0);
		return ComputeNumberOfWaysToH(top, maximum_step, numberOfWaysToH);
	}
}