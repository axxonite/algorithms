// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

#define TEST 0

struct Player 
{
	int height;

	bool operator < ( const Player& rhs ) const
	{
		return height < rhs.height;
	}
};

class Team 
{
public:
	explicit Team( const vector<int>& height ) 
	{
		for ( int h : height ) 
			players_.emplace_back( Player{ h } );
	}

	// Checks if A can be placed in front of B.
	static bool valid_placement_exists( const Team& a, const Team& b ) 
	{
		return true;
	}

private:
	vector<Player> players_;
};

#pragma region Test

void TeamPhotoTest()
{
#if TEST
	vector<int> height = { 1, 5, 4 };
	Team t1( height );
	height = { 2, 3, 4 };
	Team t2( height );
	assert( !Team::valid_placement_exists( t1, t2 ) && !Team::valid_placement_exists( t2, t1 ) );
	height = { 0, 3, 2 };
	Team t3( height );
	assert( Team::valid_placement_exists( t3, t1 ) && !Team::valid_placement_exists( t1, t3 ) && Team::valid_placement_exists( t3, t2 ) && !Team::valid_placement_exists( t1, t2 ) );
	height = { 1, 4, 2 };
	Team t4( height );
	assert( !Team::valid_placement_exists( t4, t3 ) );
	assert( !Team::valid_placement_exists( t3, t4 ) );
#endif
}

#pragma endregion
