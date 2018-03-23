// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	struct Coordinate
	{
		int x, y;
	};

	void MarkBoundaryRegion( int x, int y, vector<vector<char>>& board )
	{
		queue<Coordinate> q;
		q.emplace( Coordinate{ x, y } );
		while ( !q.empty() )
		{
			auto cur = q.front();
			q.pop();
			// Note that it's ol, and more elegant here, to queue up invalid cells that will then be rejected later.
			if ( cur.x >= 0 && cur.y >= 0 && cur.x < board.size() && cur.y < board[0].size() && board[cur.x][cur.y] == 'W' )
			{
				board[cur.x][cur.y] = '*';
				q.emplace( Coordinate{ cur.x - 1, cur.y } );
				q.emplace( Coordinate{ cur.x + 1, cur.y } );
				q.emplace( Coordinate{ cur.x, cur.y - 1 } );
				q.emplace( Coordinate{ cur.x, cur.y + 1 } );
			}
		}
	}

	void FillSurroundedRegions( vector<vector<char>>& board )
	{
		for ( int i = 0; i < board.size(); ++i )
		{
			if ( board[i][0] == 'W' )
				MarkBoundaryRegion( i, 0, board );
			if ( board[i].back() == 'W' )
				MarkBoundaryRegion( i, board[0].size() - 1, board );
		}

		for ( int i = 0; i < board[0].size(); ++i )
		{
			if ( board[0][i] == 'W' )
				MarkBoundaryRegion( 0, i, board );
			if ( board.back()[i] == 'W' )
				MarkBoundaryRegion( board.size() - 1, i, board );
		}

		for ( int x = 0; x < board.size(); ++x )
		{
			for ( auto& c : board[x] )
				// The cell can be *, W or B. * => W, W => B, and B is B.
				c = c == '*' ? 'W' : 'B';
		}
	}
}