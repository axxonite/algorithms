#include "stdafx.h"
#include "GraphVertex.h"

namespace Solutions
{
	// We need this struct to order the vertices.
	struct DijkstraSet
	{
		// Note that everything must be const here to compile.
		bool operator () (const GraphVertex* a, const GraphVertex* b) const
		{
			return a->dist < b->dist || (a->dist == b->dist && a < b);
		}
	};


	bool DijkstraRelax(GraphVertex* src, GraphVertex* dest, int cost)
	{
		// Check if the current path's cost is cheaper than the existing path's cost.
		if (src->dist < numeric_limits<int>::max() && (src->dist + cost) < dest->dist)
		{
			dest->dist = src->dist + cost;
			// Remember to keep track of the predecessor.
			dest->pred = src;
			return true;
		}
		return false;
	}

	// Dijkstra requires a source. The source's distance is set to zero. Note that all vertices should be set to the maximum possible distance at the onset.
	// We use a sorted set to keep track of the shortest path vertex.
	void Dijkstra(vector<GraphVertex*> G, int src)
	{
		G[src]->dist = 0;
		set<GraphVertex*, DijkstraSet> candidates;
		candidates.emplace(G[src]);
		while (!candidates.empty())
		{
			auto shortest_path = *candidates.begin();
			candidates.erase(candidates.begin());
			// Go over all edges
			for (auto e : shortest_path->edges)
			{
				if (DijkstraRelax(shortest_path, e.dst, e.weight))
				{
					// Remove and insert the node so it gets sorted again.
					candidates.erase(e.dst);
					candidates.emplace(e.dst);
				}
			}
		}
	}
}