// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	vector<int> MatrixInSpiralOrder( vector<vector<int>> matrix )
	{
		const array<int, 2> directions[] = { { 1, 0 },{ 0, 1 },{ -1, 0 },{ 0, -1 } };
		vector<int> result;
		int x = 0, y = 0, dirIndex = 0, minValue = 0, maxValue = matrix.size();
		for ( int i = 0; i < matrix.size() * matrix.size(); ++i )
		{
			result.emplace_back( matrix[y][x] );
			int nextX = x + directions[dirIndex][0], nextY = y + directions[dirIndex][1];
			// We could change the matrix value to zero to indicate it was visited, but I prefer to leave the matrix untouched (how would we know if zero is a valid value in the matrix?)
			if ( dirIndex == 3 && nextX == minValue && nextY == minValue )
				minValue++, maxValue--;
			if ( nextX == maxValue || nextY == maxValue || nextX < minValue || nextY < minValue )
			{
				dirIndex = ( dirIndex + 1 ) % 4; // Note the modulo trick here.
				nextX = x + directions[dirIndex][0], nextY = y + directions[dirIndex][1];
			}

			x = nextX, y = nextY;
		}
		return result;
	}
}