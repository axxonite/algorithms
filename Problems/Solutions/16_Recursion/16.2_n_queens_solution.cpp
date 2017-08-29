// Copyright (c) 2013 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	// Test if a newly placed queen will conflict any earlier queens placed before.
	bool IsValid(const vector<int>& col_placement)
	{
		int row_id = col_placement.size() - 1;
		for (int i = 0; i < row_id; ++i)
		{
			int diff = abs(col_placement[i] - col_placement[row_id]);
			if (diff == 0 || diff == row_id - i)
				return false;			// A column or diagonal constraint is violated.
		}
		return true;
	}

	void SolveNQueens(int n, int row, vector<int>* col_placement, vector<vector<int>>* result)
	{
		if (row == n)
			result->emplace_back(*col_placement); 		// All queens are legally placed.
		else
		{
			for (int col = 0; col < n; ++col)
			{
				col_placement->emplace_back(col);
				if (IsValid(*col_placement))
					SolveNQueens(n, row + 1, col_placement, result);
				col_placement->pop_back();
			}
		}
	}

	vector<vector<int>> NQueens(int n)
	{
		vector<vector<int>> result;
		SolveNQueens(n, 0, make_unique<vector<int>>().get(), &result);
		return result;
	}
}
