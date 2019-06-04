#include "stdafx.h"
#include "GraphVertex.h"
#include "..\..\Solutions\19_Graphs\19.5_clone_graph_solution.h"
#include "..\..\Solutions\19_Graphs\BellmanFord_solution.h"
#include "..\..\Solutions\19_Graphs\Dijkstra_solution.h"

namespace Solutions
{
	bool Johnson(vector<GraphVertex*> G, vector<vector<int>>& result)
	{
		// create a graph for the weight offsets.
		auto weightOffsets = Solutions::CloneGraph(G);

		// add sink vertex so we visit all vertices with BellmanFord.
		auto s = make_shared<GraphVertex>(GraphVertex());
		for (auto v : weightOffsets)
			s->edges.emplace_back(Edge{ v, 0 });
		weightOffsets.emplace_back(s.get());

		// Perform Bellman Ford and check for negative weight cycles.
		if (!Solutions::BellmanFord(weightOffsets, weightOffsets.size() - 1))
			return false;

		// Remove any negative weights in the original graphs by offsetting the weights.
		for (int src = 0; src < G.size(); ++src)
			for (int dest = 0; dest < G[src]->edges.size(); ++dest)
				G[src]->edges[dest].weight += weightOffsets[src]->dist - weightOffsets[src]->edges[dest].dst->dist;
		
		for (int src = 0; src < G.size(); ++src)
		{
			// Perform Dijkstra starting from every vertex in the original graph.
			// Remember to reset the distances on each iteration.
			for (int j = 0; j < G.size(); ++j)
				G[j]->dist = numeric_limits<int>::max();
			Solutions::Dijkstra(G, src);

			// Compute result from Dijkstra result and remove the weight offsets.
			for (int dest = 0; dest < G.size(); ++dest)
				result[src][dest] = G[dest]->dist - weightOffsets[src]->dist + weightOffsets[dest]->dist;
		}
		return true;
	}
}