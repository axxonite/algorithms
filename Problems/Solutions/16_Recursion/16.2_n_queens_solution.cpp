// Copyright (c) 2013 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	// Test if a newly placed queen will conflict any earlier queens placed before.
	bool IsValid(const vector<int>& colPlacementPerRow)
	{
		int currentRow = colPlacementPerRow.size() - 1; // start with last row we have added.
		for (int i = 0; i < currentRow; ++i)
		{
			int diff = abs(colPlacementPerRow[i] - colPlacementPerRow[currentRow]);
			// Diff will be 0 if there's already a queen on that column
			// Diff will be currentRow - 1 if there's a queen on the diagonal.
			if (diff == 0 || diff == currentRow - i)
				return false;			// A column or diagonal constraint is violated.
		}
		return true;
	}

	void SolveNQueens(int n, int row, vector<int>& colPlacement, vector<vector<int>>& result)
	{
		// Add the result if we're on the last row.
		if (row == n)
			result.emplace_back(colPlacement); 		// All queens are legally placed.
		else
		{
			// Try every possible column.
			for (int col = 0; col < n; ++col)
			{
				colPlacement.emplace_back(col);
				// If the column is valid, enumerate placements for the following row.
				if (IsValid(colPlacement))
					SolveNQueens(n, row + 1, colPlacement, result);
				colPlacement.pop_back();
			}
		}
	}

	vector<vector<int>> NQueens(int n)
	{
		vector<vector<int>> result;
		vector<int> colPlacement;
		SolveNQueens(n, 0, colPlacement, result);
		return result;
	}
}
