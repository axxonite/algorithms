// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	struct Coordinate
	{
		int x, y;
	};

	void FlipColor( int x, int y, vector<deque<bool>>& a )
	{
		queue<Coordinate> q;
		q.emplace( Coordinate{ x, y } );
		bool color = a[x][y];
		a[x][y] = !a[x][y];
		while ( !q.empty() )
		{
			auto cur = q.front();
			q.pop();
			const array<Coordinate, 4> directions = { Coordinate{ 1, 0 },{ 0, 1 },{ -1, 0 },{ 0, -1 } };
			for ( int i = 0; i < 4; ++i )
			{
				int nextX = cur.x + directions[i].x, nextY = cur.y + directions[i].y;
				if ( nextX >= 0 && nextY >= 0 && nextX < a.size() && nextY < a[0].size() && a[x][y] == color )
				{
					// Note that we must flip the color, then queue the cell. This will allow us to properly flip the colors and making sure they don't get queued again.
					a[nextX][nextY] = !color;
					q.emplace( Coordinate{ nextX, nextY } );
				}
			}
		}
	}
}