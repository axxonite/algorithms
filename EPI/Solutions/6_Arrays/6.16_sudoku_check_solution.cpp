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
}