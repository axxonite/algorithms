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
					a[nextX][nextY] = !color;
					q.emplace( Coordinate{ nextX, nextY } );
				}
			}
		}
	}

	void FlipColor2(int x, int y, vector<deque<bool>>& a)
	{
		// start from x,y. Take color from that point. Any adjacent entries of that color get changes to the opposite color.
		queue<Coordinate> q;
		q.emplace(Coordinate{ x, y });
		bool regionColor = a[x][y];
		while (!q.empty())
		{
			auto cur = q.front();
			q.pop();
			if (cur.x >= 0 && cur.x < a.size() && cur.y >= 0 && cur.y < a[0].size() && a[cur.x][cur.y] == regionColor)
			{
				a[cur.x][cur.y] = !regionColor;
				q.emplace(Coordinate{ x - 1, y });
				q.emplace(Coordinate{ x + 1, y });
				q.emplace(Coordinate{ x, y - 1 });
				q.emplace(Coordinate{ x, y + 1 });
			}
		}
	}
}