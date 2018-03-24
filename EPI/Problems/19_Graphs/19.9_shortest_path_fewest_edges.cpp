// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

#define TEST 0

struct DijkstraGraphVertex 
{
	struct DistanceWithFewestEdges 
	{
		int distance, minNumEdges;
	};
	DistanceWithFewestEdges distanceWithFewestEdges = DistanceWithFewestEdges{ numeric_limits<int>::max(), 0 };

	struct VertexWithDistance 
	{
		DijkstraGraphVertex& vertex;
		int distance;
	};
	vector<VertexWithDistance> edges;
	int id;  // The id of this vertex.
	const DijkstraGraphVertex* pred = nullptr;  // The predecessor in the shortest path.
};

void OutputShortestPath(const DijkstraGraphVertex* v);

void DijkstraShortestPath( DijkstraGraphVertex* s, const DijkstraGraphVertex* t )
{
}

#pragma region Test

void OutputShortestPath( const DijkstraGraphVertex* v )
{
	if ( v )
	{
		OutputShortestPath( v->pred );
		cout << v->id << " ";
	}
}

// DBH test
void DijkstraShortestPathSmallTest() 
{
	vector<DijkstraGraphVertex> G;
	for ( int i = 0; i < 9; ++i ) 
	{
		G.emplace_back( DijkstraGraphVertex() );
		G[i].id = i;
	}

	// G[0] is the source node that connects to 8 other nodes.
	G[0].edges.push_back( DijkstraGraphVertex::VertexWithDistance{ G[1], 13 } );  // 0-1
	G[1].edges.push_back( DijkstraGraphVertex::VertexWithDistance{ G[0], 13 } );  // 1-0

	G[0].edges.push_back( DijkstraGraphVertex::VertexWithDistance{ G[2], 24 } );  // 0-2
	G[2].edges.push_back( DijkstraGraphVertex::VertexWithDistance{ G[0], 24 } );  // 2-0

	G[0].edges.push_back( DijkstraGraphVertex::VertexWithDistance{ G[3], 28 } );  // 0-3
	G[3].edges.push_back( DijkstraGraphVertex::VertexWithDistance{ G[0], 28 } );  // 3-0

	G[0].edges.push_back( DijkstraGraphVertex::VertexWithDistance{ G[4], 25 } );  // 0-4
	G[4].edges.push_back( DijkstraGraphVertex::VertexWithDistance{ G[0], 25 } );  // 4-0

	G[0].edges.push_back( DijkstraGraphVertex::VertexWithDistance{ G[5], 30 } );  // 0-5
	G[5].edges.push_back( DijkstraGraphVertex::VertexWithDistance{ G[0], 30 } );  // 5-0

	G[0].edges.push_back( DijkstraGraphVertex::VertexWithDistance{ G[6], 31 } );  // 0-6
	G[6].edges.push_back( DijkstraGraphVertex::VertexWithDistance{ G[0], 31 } );  // 6-0

	G[0].edges.push_back( DijkstraGraphVertex::VertexWithDistance{ G[7], 10 } );  // 0-7
	G[7].edges.push_back( DijkstraGraphVertex::VertexWithDistance{ G[0], 10 } );  // 7-0

	G[0].edges.push_back( DijkstraGraphVertex::VertexWithDistance{ G[8], 29 } );  // 0-8
	G[8].edges.push_back( DijkstraGraphVertex::VertexWithDistance{ G[0], 29 } );  // 8-0

	G[1].edges.push_back( DijkstraGraphVertex::VertexWithDistance{ G[8], 7 } );  // 1-8
	G[8].edges.push_back( DijkstraGraphVertex::VertexWithDistance{ G[1], 7 } );  // 8-1

	G[2].edges.push_back( DijkstraGraphVertex::VertexWithDistance{ G[8], 1 } );  // 2-8
	G[8].edges.push_back( DijkstraGraphVertex::VertexWithDistance{ G[2], 1 } );  // 8-2

	G[7].edges.push_back( DijkstraGraphVertex::VertexWithDistance{ G[8], 16 } );  // 7-8
	G[8].edges.push_back( DijkstraGraphVertex::VertexWithDistance{ G[7], 16 } );  // 8-7

	int s = 0;  // Source is G[0].
	int t = 2;  // Destination is G[2].

	// Minimum distance path should be:
	// G[0] => G[1] => G[8] => G[2],
	// distance is: 13 + 7 + 1 = 21.

	DijkstraShortestPath( &G[s], &G[t] );
	cout << endl << "Min distance: " << G[t].distanceWithFewestEdges.distance << endl;
	assert( G[t].distanceWithFewestEdges.distance == 21 );
	cout << "Number of edges: " << G[t].distanceWithFewestEdges.minNumEdges << endl;
	assert( G[t].distanceWithFewestEdges.minNumEdges == 3 );
}

void DijkstraShortestPathTest()
{
#if TEST
	default_random_engine gen( ( random_device() )( ) );
	int n;
	uniform_int_distribution<int> dis( 2, 1000 );
	n = dis( gen );
	vector<DijkstraGraphVertex> G;
	for ( int i = 0; i < n; ++i ) 
		G.emplace_back( DijkstraGraphVertex() );
	uniform_int_distribution<int> dis2( 1, n * ( n - 1 ) / 2 );
	int m = dis2( gen );
	vector<deque<bool>> is_edge_exist( n, deque<bool>( n, false ) );
	// Make the graph as connected.
	for ( int i = 1; i < n; ++i )
	{
		uniform_int_distribution<int> dis( 1, 100 );
		int len = dis( gen );
		G[i - 1].edges.emplace_back( DijkstraGraphVertex::VertexWithDistance{ G[i], len } );
		G[i].edges.emplace_back( DijkstraGraphVertex::VertexWithDistance{ G[i - 1], len } );
		is_edge_exist[i - 1][i] = is_edge_exist[i][i - 1] = true;
	}

	// Generate edges randomly.
	m -= ( n - 1 );
	uniform_int_distribution<int> dis_n( 0, n - 1 );
	while ( m-- > 0 ) 
	{
		int a, b;
		do
			a = dis_n( gen ), b = dis_n( gen );
		while ( a == b || is_edge_exist[a][b] == true );
		is_edge_exist[a][b] = is_edge_exist[b][a] = true;
		uniform_int_distribution<int> one_to_100( 1, 100 );
		int len = one_to_100( gen );
		G[a].edges.emplace_back( DijkstraGraphVertex::VertexWithDistance{ G[b], len } );
		G[b].edges.emplace_back( DijkstraGraphVertex::VertexWithDistance{ G[a], len } );
	}
	int s = dis_n( gen ), t = dis_n( gen );
	cout << "source = " << s << ", terminal = " << t << endl;
	DijkstraShortestPath( &G[s], &G[t] );
	cout << endl
		<< G[t].distanceWithFewestEdges.distance << " "
		<< G[t].distanceWithFewestEdges.minNumEdges << endl;
	DijkstraShortestPathSmallTest();
#endif
}

#pragma endregion
