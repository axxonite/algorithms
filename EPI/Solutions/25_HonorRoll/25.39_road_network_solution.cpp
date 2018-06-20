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

		// Note the O(n^3) loop.
		for ( int k = 0; k < g.size(); ++k )
			for ( int i = 0; i < g.size(); ++i )
				if (g[i][k] != numeric_limits<int>::max())
					for ( int j = 0; j < g.size(); ++j )
						// we have triplets of cities, that we treat as i->j->k. Make sure we have shortest path distances from i->j and from j->k.
						if ( g[k][j] != numeric_limits<int>::max() )
							g[i][j] = min( g[i][j], g[i][k] + g[k][j] ); // Then the distance from i->k->j is a candidate for minimal value from i->k.
	}

	HighwaySection FindBestProposals( const vector<HighwaySection>& H, const vector<HighwaySection>& P, int n )
	{
		// Build the graph of connected cities. Use an adjacency matrix.
		vector<vector<int>> shortestPaths( n, vector<int>( n, numeric_limits<int>::max() ) );
		for ( int i = 0; i < n; ++i )
			shortestPaths[i][i] = 0;

		for ( const HighwaySection& h : H )
			shortestPaths[h.x][h.y] = shortestPaths[h.y][h.x] = h.distance; // Set distances going both directions.

		// Fill up all the shortest paths between cities.
		FloydMarshall( shortestPaths );

		// Test every proposal.
		int bestSavings = numeric_limits<int>::min();
		HighwaySection bestProposal = { -1, -1, 0 };
		for ( const HighwaySection& p : P )
		{
			// Test the effect of the proposal over every pair of cities.
			int proposalSavings = 0;
			for ( int a = 0; a < n; ++a )
			{
				for ( int b = 0; b < n; ++b )
				{
					// We go from a->x->y->b, or from a->y->x->b, and pick the shortest path of the two. Compare with original path a->b to see how much we save from going through the extra route
					int savings = shortestPaths[a][b] - min( shortestPaths[a][p.x] + p.distance + shortestPaths[p.y][b], shortestPaths[a][p.y] + p.distance + shortestPaths[p.x][b] );
					proposalSavings += max( savings, 0 );
				}
			}
			if ( proposalSavings > bestSavings )
				bestSavings = proposalSavings, bestProposal = p;
		}
		return bestProposal;
	}
}