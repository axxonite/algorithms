// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	// todo this was never explained.
	bool BellmanFord(const vector<vector<double>>& G, int source)
	{
		vector<double> dis_to_source(G.size(), numeric_limits<double>::max());
		dis_to_source[source] = 0;

		for (size_t times = 1; times < G.size(); ++times)
		{
			bool have_update = false;
			for (size_t i = 0; i < G.size(); ++i)
			{
				for (size_t j = 0; j < G[i].size(); ++j)
				{
					if (dis_to_source[i] != numeric_limits<double>::max() && dis_to_source[j] > dis_to_source[i] + G[i][j])
					{
						have_update = true;
						dis_to_source[j] = dis_to_source[i] + G[i][j];
					}
				}
			}

			// No update in this iteration means no negative cycle.
			if (have_update == false)
				return false;
		}

		// Detects cycle if there is any further update.
		for (size_t i = 0; i < G.size(); ++i)
		{
			for (size_t j = 0; j < G[i].size(); ++j)
			{
				if (dis_to_source[i] != numeric_limits<double>::max() &&
					dis_to_source[j] > dis_to_source[i] + G[i][j])
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
			for (double& edge : edge_list)
				edge = -log10(edge);
		}

		// Uses Bellman-Ford to find negative weight cycle.
		return BellmanFord(G, 0);
	}
	
}
