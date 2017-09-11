// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	int MinimumPathWeight(const vector<vector<int>>& triangle)
	{
		if (triangle.empty())
			return 0;

		// As we iterate, prev_row stores the minimum path sum to each entry in triangle[i - 1].
		vector<int> prevRow(triangle.front());
		for (int i = 1; i < triangle.size(); ++i)
		{
			// Stores the minimum path sum to each entry in triangle[i].
			vector<int> curRow(triangle[i]);
			curRow.front() += prevRow.front(); // For the first element.
			for (int j = 1; j < curRow.size() - 1; ++j)
				curRow[j] += min(prevRow[j - 1], prevRow[j]);
			curRow.back() += prevRow.back(); // For the last element.

			// Uses swap to assign curRow's content to prev_row in O(1) time.
			prevRow.swap(curRow);
		}
		return *min_element(prevRow.cbegin(), prevRow.cend());
	}
}
