// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

vector<int> IntersectTwoSortedArrays(const vector<int>& a, const vector<int>& b)
{
	vector<int> result;
	int i = 0, j = 0;
	while (i < a.size() && j < b.size())
	{
		if (a[i] == b[j] && (i == 0 || a[i] != a[i - 1]))
		{
			result.emplace_back(a[i]);
			++i , ++j;
		}
		else if (a[i] < b[j])
			++i;
		else
			++j;
	}
	return result;
}

// no test