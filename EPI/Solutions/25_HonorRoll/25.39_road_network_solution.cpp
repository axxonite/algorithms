// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	struct HighwaySection
	{
		int x, y;
		double distance;
	};

	void FloydMarshall( vector<vector<int>>& g )
	{
		// O(n^3). Floyd-Marshall effectively picks an in-between city k and updates shortest paths for all pairs of cities, going through the intermediate city, aka i->k->j.
		// I'm a little unclear how this order of evaluation guarantees every shortest possible path is evaluated.
		for ( int k = 0; k < g.size(); ++k )
			for ( int i = 0; i < g.size(); ++i )
				for ( int j = 0; j < g.size(); ++j )
					if ( g[i][k] != numeric_limits<int>::max() && g[k][j] != numeric_limits<int>::max() ) // If both endpoints of i->k->j have shortest path values
						g[i][j] = min( g[i][j], g[i][k] + g[k][j] ); // Then the distance from i->k->j is a candidate for minimal value from i->k.
	}

	HighwaySection FindBestProposals( const vector<HighwaySection>& H, const vector<HighwaySection>& P, int n )
	{
		// Build the graph of connected cities.
		vector<vector<int>> graph( n, vector<int>( n, numeric_limits<int>::max() ) );
		for ( int i = 0; i < n; ++i )
			graph[i][i] = 0;

		for ( const HighwaySection& h : H )
			graph[h.x][h.y] = graph[h.y][h.x] = h.distance; // Set distances going both directions.

															// Fill up all the shortest paths between cities.
		FloydMarshall( graph );

		// Test every proposal.
		int bestSavings = numeric_limits<int>::min();
		HighwaySection bestProposal = { -1, -1, 0 };
		for ( const HighwaySection& p : P )
		{
			int proposalSavings = 0;
			for ( int a = 0; a < n; ++a )
			{
				for ( int b = 0; b < n; ++b )
				{
					// We go from a->x->y->b, or from a->y->x->b, and pick the shortest path of the two. Compare with original path a->b to see how much we save from going through the extra route.
					// The math is slightly tricky here.
					int savings = graph[a][b] - min( graph[a][p.x] + p.distance + graph[p.y][b], graph[a][p.y] + p.distance + graph[p.x][b] );
					proposalSavings += max( savings, 0 );
				}
			}
			if ( proposalSavings > bestSavings )
				bestSavings = proposalSavings, bestProposal = p;
		}
		return bestProposal;
	}
}