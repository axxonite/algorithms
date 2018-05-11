// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	bool TestArea( const vector<vector<int>>& grid, int startX, int startY, int endX, int endY )
	{
		vector<bool> present( grid.size() + 1, false );
		for ( int x = startX; x < endX; ++x )
		{
			for ( int y = startY; y < endY; ++y )
			{
				if ( grid[x][y] != 0 && present[grid[x][y]] )
					return false;
				present[grid[x][y]] = true;
			}
		}
		return true;
	}

	bool IsValidSudoku( const vector<vector<int>>& grid )
	{
		// test all columns
		for ( int x = 0; x < grid.size(); ++x )
		{
			if ( !TestArea( grid, x, 0, x + 1, grid[0].size() ) )
				return false;
		}

		// test all rows
		for ( int y = 0; y < grid[0].size(); y++ )
		{
			if ( !TestArea( grid, 0, y, grid.size(), y + 1 ) )
				return false;
		}

		// test sub grids.
		int subGridSize = sqrt( grid.size() ), x = 0, y = 0;
		for ( int x = 0; x < subGridSize; ++x )
		{
			for ( int y = 0; y < subGridSize; ++y )
			{
				if ( !TestArea( grid, x * subGridSize, y * subGridSize, ( x + 1 ) * subGridSize, ( y + 1 ) * subGridSize ) )
					return false;
			}
		}

		return true;
	}

	bool IsValidSudoku2(const vector<vector<int>>& grid)
	{
		vector<int> rows(9, 0), columns(9, 0), subgrids(9, 0);
		for (int i = 0; i < grid.size(); ++i)
		{
			for (int j = 0; j < grid[0].size(); ++j)
			{
				if (grid[i][j])
				{
					int mask = 1 << grid[i][j];
					int grid = (i / 3) * 3 + j / 3;
					if ((rows[i] & mask) || (columns[j] & mask) || (subgrids[grid] & mask))
						return false;
					rows[i] |= mask, columns[j] |= mask, subgrids[grid] |= mask;
				}
			}
		}
		return true;
	}
}