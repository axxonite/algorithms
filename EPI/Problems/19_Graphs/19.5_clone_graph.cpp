// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

#define TEST 0

struct CloneGraphVertex 
{
	int label;
	vector<CloneGraphVertex*> edges;
};

CloneGraphVertex* CloneGraph( CloneGraphVertex* G )
{
	return nullptr;
}

#pragma region Test

vector<int> CopyLabels( const vector<CloneGraphVertex*>& edges )
{
	vector<int> labels;
	for ( CloneGraphVertex* e : edges )
		labels.emplace_back( e->label );
	return labels;
}

void CheckGraph( CloneGraphVertex* node, const vector<CloneGraphVertex>& G )
{
	unordered_set<CloneGraphVertex*> vertex_set;
	queue<CloneGraphVertex*> q;
	q.emplace( node );
	vertex_set.emplace( node );
	while ( !q.empty() ) 
	{
		auto vertex = q.front();
		q.pop();
		assert( vertex->label < G.size() );
		vector<int> label1 = CopyLabels( vertex->edges ),
		label2 = CopyLabels( G[vertex->label].edges );
		sort( label1.begin(), label1.end() ), sort( label2.begin(), label2.end() );
		assert( equal( label1.begin(), label1.end(), label2.begin(), label2.end() ) );
		for ( CloneGraphVertex* e : vertex->edges )
		{
			if ( vertex_set.find( e ) == vertex_set.end() )
			{
				vertex_set.emplace( e );
				q.emplace( e );
			}
		}
	}
}

void CloneGraphTest()
{
#if TEST
	default_random_engine gen( ( random_device() )( ) );
	for ( int times = 0; times < 100; ++times ) 
	{
		vector<CloneGraphVertex> G;
		int n;
		uniform_int_distribution<int> n_dis( 2, 101 );
		n = n_dis( gen );
		for ( int i = 0; i < n; ++i )
			G.emplace_back( CloneGraphVertex{ i } );
		uniform_int_distribution<int> dis( 1, n * ( n - 1 ) / 2 );
		int m = dis( gen );
		vector<deque<bool>> is_edge_exist( n, deque<bool>( n, false ) );
		// Make the graph become connected.
		for ( int i = 1; i < n; ++i ) 
		{
			G[i - 1].edges.emplace_back( &G[i] );
			G[i].edges.emplace_back( &G[i - 1] );
			is_edge_exist[i - 1][i] = is_edge_exist[i][i - 1] = true;
		}

		// Generate some edges randomly.
		m -= ( n - 1 );
		while ( m-- > 0 )
		{
			int a, b;
			uniform_int_distribution<int> dis( 0, n - 1 );
			do
				a = dis( gen ), b = dis( gen );
			while ( a == b || is_edge_exist[a][b] == true );
			is_edge_exist[a][b] = is_edge_exist[b][a] = true;
			G[a].edges.emplace_back( &G[b] );
			G[b].edges.emplace_back( &G[a] );
		}
		auto res = CloneGraph( &G[0] );
		CheckGraph( res, G );
	}
#endif
}

#pragma endregion
