// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	vector<int> MatrixInSpiralOrder( vector<vector<int>> matrix )
	{
		vector<int> result;
		// first value is y, second value is x.
		const tuple<int, int> directions[] = { { 0, 1 },{ 1, 0 },{ 0, -1 },{ -1, 0 } };
		int directionIndex = 0, x = 0, y = 0, minxy = 0, maxy = matrix.size() - 1, maxx = matrix[0].size() - 1;
		for (int i = 0; i < matrix.size() * matrix[0].size(); ++i)
		{
			result.emplace_back(matrix[y][x]);
			int nextX = x + get<1>(directions[directionIndex]), nextY = y + get<0>(directions[directionIndex]);
			if (nextX < minxy || nextX > maxx || nextY < minxy || nextY > maxy) // technically nextY < minxy is unnecessary because of the next condition below.
				directionIndex++;
			if (nextX == minxy && nextY == minxy)
				directionIndex = 0, minxy++, maxx--, maxy--;
			x = x + get<1>(directions[directionIndex]), y = y + get<0>(directions[directionIndex]);
		}
		return result;
	}
}