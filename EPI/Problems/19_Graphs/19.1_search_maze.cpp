// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

#define TEST 0

typedef enum { WHITE, BLACK } Color;

struct Coordinate 
{
	bool operator==( const Coordinate& that ) const 
	{
		return x == that.x && y == that.y;
	}

	int x, y;
};

vector<Coordinate> SearchMaze( vector<vector<Color>> maze, const Coordinate& s, const Coordinate& e ) 
{
	return {};
}

#pragma region Test

void SearchMazeTest()
{
#if TEST
	default_random_engine gen( ( random_device() )( ) );
	for ( int times = 0; times < 1000; ++times ) 
	{
		int n, m;
		uniform_int_distribution<int> dis( 1, 30 );
		n = dis( gen );
		m = dis( gen );
		vector<vector<Color>> maze( n, vector<Color>( m ) );
		for ( int i = 0; i < n; ++i )
		{
			for ( int j = 0; j < m; ++j ) 
			{
				uniform_int_distribution<int> zero_or_one( 0, 1 );
				maze[i][j] = zero_or_one( gen ) ? WHITE : BLACK;
			}
		}
		vector<Coordinate> white;
		for ( int i = 0; i < n; ++i ) 
		{
			for ( int j = 0; j < m; ++j ) 
			{
				if ( maze[i][j] == WHITE )
					white.emplace_back( Coordinate{ i, j } );
				//cout << maze[i][j] << ' ';
			}
			//cout << endl;
		}
		//cout << endl;
		// this doesn't actually test that the path returned is the shortest one, or even that the path doesn't cross any walls.
		if ( white.size() ) 
		{
			uniform_int_distribution<int> dis( 0, white.size() - 1 );
			int start = dis( gen );
			int end = dis( gen );
			//cout << white[start].x << ' ' << white[start].y << endl;
			//cout << white[end].x << ' ' << white[end].y << endl;
			vector<Coordinate> path = SearchMaze( maze, white[start], white[end] );
			if ( !path.empty() )
				assert( white[start] == path.front() && white[end] == path.back() );
			for ( int i = 0; i < path.size(); ++i ) 
			{
				if ( i > 0 ) 
					assert( abs( path[i - 1].x - path[i].x ) + abs( path[i - 1].y - path[i].y ) == 1 );
				//cout << '(' << path[i].x << ',' << path[i].y << ')' << endl;
			}
		}
	}
#endif
}

#pragma endregion
