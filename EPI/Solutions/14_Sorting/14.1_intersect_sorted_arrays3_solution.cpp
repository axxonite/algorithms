// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	vector<int> IntersectTwoSortedArrays(const vector<int>& a, const vector<int>& b)
	{
		vector<int> result;
		int i = 0, j = 0;
		while (i < a.size() && j < b.size())
		{
			// add common entry is entries in each entry are the same, AND if the entry is not the same as the last entry.
			if (a[i] == b[j] && (i == 0 || a[i] != a[i - 1]))
			{
				result.emplace_back(a[i]);
				++i, ++j;
			}
			// otherwise increment the iterator that has the smaller value.
			else if (a[i] < b[j])
				++i;
			else
				++j;
		}
		return result;
	}
}
