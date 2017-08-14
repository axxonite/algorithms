// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	int GetHeightHelper(int cases, int drops, vector<vector<int>>& f)
	{
		// Bases cases.
		if (cases == 0 || drops == 0)
			return 0;
		if (cases == 1)
			return drops;
		// Plan to use our remaining cases and drops if our first drop breaks, in which case we would be left with c - 1 cases and d - 1 drops, meaning we can test (c-1,d-1) floors if the first case breaks.
		// If the first case doesn't break, we still have the same amount of cases but one less drop. This is implemented by the following recurrence.
		if (f[cases][drops] == -1)
			f[cases][drops] = GetHeightHelper(cases, drops - 1, f) + GetHeightHelper(cases - 1, drops - 1, f) + 1;
		return f[cases][drops];
	}

	int GetHeight(int cases, int drops)
	{
		vector<vector<int>> f(cases + 1, vector<int>(drops + 1, -1)); // +1 so that we always have an element for index zero.
		return GetHeightHelper(cases, drops, f);
	}
}
