// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	bool BellmanFord(const vector<vector<double>>& G, int source)
	{
		// initialize all vertices to infinite distance, except the source vertex which starts at zero.
		vector<double> distanceToSource(G.size(), numeric_limits<double>::max());
		distanceToSource[source] = 0;

		// lemmas
		// * if dist[u] is not infinity, it is equal to the length of some path from source to u.
		// * if there is a path from s to u with at most i edges, then dist[u] is at most the length of the shortest path from source to u with at most i edges.

		// perform relaxation as many times as there are uninitialized vertices in the graph.
		for (size_t times = 1; times < G.size(); ++times)
		{
			bool haveUpdate = false;
			// iterate all vertex pairs.
			for (size_t i = 0; i < G.size(); ++i)
			{
				for (size_t j = 0; j < G[i].size(); ++j)
				{
					// dist[j] = min( dist[j], dist[i] + g[i][j] ), for is that have been initialized.
					// in words, if a vertex (with distance assigned) + edge has a lower value than the existing shortest part, assign it as the new shortest distance.
					// for each pass (iterated as times), we will compute a shortest path from the vertices that have been initialized.
					// thus we will start from source and fan out from there.

					// How does this even check that two graph nodes are connected?
					if (distanceToSource[i] != numeric_limits<double>::max() && distanceToSource[j] > distanceToSource[i] + G[i][j])
					{
						haveUpdate = true;
						distanceToSource[j] = distanceToSource[i] + G[i][j];
					}
				}
			}

			// No update in this iteration means no negative cycle.
			if (haveUpdate == false)
				return false;
		}

		// Detects cycle if there is any further update.
		for (size_t i = 0; i < G.size(); ++i)
		{
			for (size_t j = 0; j < G[i].size(); ++j)
			{
				if (distanceToSource[i] != numeric_limits<double>::max() &&
					distanceToSource[j] > distanceToSource[i] + G[i][j])
					return true;
			}
		}
		return false;
	}

	bool IsArbitrageExist(vector<vector<double>> G)
	{
		// Transforms each edge in G.
		for (vector<double>& edge_list : G)
		{
			// This assumes all nodes connected. If there was a zero in the graph, it would fail the log10.
			// normally we would have to check for that, and add a check in the Bellman-Ford algorithm to not compute a distance between those two vertices.
			for (double& edge : edge_list)
				edge = -log10(edge);
		}

		// Uses Bellman-Ford to find negative weight cycle.
		// The code is making a few assumptions that wouldn't necessarily be true:
		// The graph may not be fully connected. There might be arbitrage possible only on one side of the graph.
		// This implementation also doesn't even check that two nodes are connected.
		return BellmanFord(G, 0);
	}
	
}
