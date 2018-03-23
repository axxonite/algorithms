// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	typedef enum { WHITE, BLACK } Color;

	struct Coordinate
	{
		bool operator==( const Coordinate& that ) const
		{
			return x == that.x && y == that.y;
		}

		int x, y;
	};

	// Clever trick: block out the maze so we don't revisit cells. Very clever.
	bool SearchMaze( vector<vector<Color>>& maze, const Coordinate& s, const Coordinate& e, vector<Coordinate>& path )
	{
		if ( s.x < 0 || s.x >= maze.size() || s.y < 0 || s.y >= maze[0].size() || maze[s.x][s.y] == BLACK )
			return false;
		maze[s.x][s.y] = BLACK;
		path.emplace_back( s );
		if ( s == e )
			return true;

		if ( SearchMaze( maze, { s.x - 1, s.y }, e, path ) || SearchMaze( maze, { s.x + 1, s.y }, e, path ) ||
			SearchMaze( maze, { s.x, s.y - 1 }, e, path ) || SearchMaze( maze, { s.x, s.y + 1 }, e, path ) )
			return true;
		path.pop_back();
		return false;
	}

	vector<Coordinate> SearchMaze( vector<vector<Color>> maze, const Coordinate& s, const Coordinate& e )
	{
		vector<Coordinate> path;
		SearchMaze( maze, s, e, path );
		return path;
	}
}