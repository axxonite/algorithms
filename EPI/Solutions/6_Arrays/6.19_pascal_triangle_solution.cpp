// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	vector<vector<int>> GeneratePascalTriangle(int rows)
	{
		vector<vector<int>> result;
		for (int i = 0; i < rows; ++i) 
		{
			vector<int> row;
			for (int j = 0; j <= i; ++j) 
				// Sets this entry to the sum of the two above adjacent entries if exist.
				row.emplace_back(0 < j && j < i ? result.back()[j - 1] + result.back()[j] : 1);
			result.emplace_back(row);
		}
		return result;
	}

}