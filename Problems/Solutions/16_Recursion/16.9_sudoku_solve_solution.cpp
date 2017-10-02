// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	const int kEmptyEntry = 0;

	bool CanAddVal(const vector<vector<int>>& grid, int x, int y, int val)
	{
		// Check if the value is already on this column or row.
		for (int k = 0; k < grid.size(); ++k)
			if (val == grid[k][y])
				return false;
		for (int k = 0; k < grid[0].size(); ++k)
			if (val == grid[x][k])
				return false;

		// Check region constraints.
		int regionSize = sqrt(grid.size());
		int regionX = x / regionSize, regionY = y / regionSize;
		for (int i = 0; i < regionSize; ++i)
			for (int j = 0; j < regionSize; ++j)
				if (val == grid[regionSize * regionX + i][regionSize * regionY + j])
					return false;
		return true;
	}

	bool SolvePartialSudoku(int x, int y, vector<vector<int>>& grid)
	{
		if (x == grid.size())
		{
			x = 0; // Start a new row.
			if (++y == grid[x].size())
				return true; // Entire matrix has been filled without conflict.
		}

		if (grid[x][y] != kEmptyEntry)
			return SolvePartialSudoku(x + 1, y, grid); // Skip nonempty entries.

		for (int val = 1; val <= grid.size(); ++val)
		{
			// It's substantially quicker to check if entry val conflicts with any of the constraints if we add it at (x,y) before adding it, rather than adding it and then checking all constraints.
			// The reason is that we know we are starting with a valid configuration, and the only entry which can cause a problem is entry val at (x,y).
			if (CanAddVal(grid, x, y, val))
			{
				grid[x][y] = val;
				if (SolvePartialSudoku(x + 1, y, grid))
					return true;
			}
		}

		grid[x][y] = kEmptyEntry; // Undo assignment.
		return false;
	}

	bool SolveSudoku(vector<vector<int>>& grid)
	{
		return SolvePartialSudoku(0, 0, grid);
	}
}
