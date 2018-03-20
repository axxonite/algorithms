// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

#define TEST 0

struct GraphVertex 
{
	vector<GraphVertex*> edges;
	// Set max_distance = 0 to indicate unvisited vertex.
	int max_distance = 0;
};

int FindLargestNumberTeams( vector<GraphVertex>* G ) 
{
	return 0;
}

#pragma region Test

void FindLargestNumberTeamsTest()
{
#if TEST
	vector<GraphVertex> G( 3 );
	G[0].edges.emplace_back( &G[2] );
	G[1].edges.emplace_back( &G[2] );
	assert( 2 == FindLargestNumberTeams( &G ) ); 
#endif
}

#pragma endregion