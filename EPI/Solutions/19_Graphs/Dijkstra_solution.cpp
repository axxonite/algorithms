#include "stdafx.h"
#include "GraphVertex.h"

namespace Solutions
{
	struct DijkstraSet
	{
		bool operator () (const GraphVertex* a, const GraphVertex* b) const
		{
			return a->dist < b->dist || (a->dist == b->dist && a < b);
		}
	};

	bool DijkstraRelax(GraphVertex* u, GraphVertex* v, int weight)
	{
		if (u->dist < numeric_limits<int>::max() && (u->dist + weight) < v->dist)
		{
			v->dist = u->dist + weight;
			v->pred = u;
			return true;
		}
		return false;
	}

	void Dijkstra(vector<GraphVertex*> G, int src)
	{
		G[src]->dist = 0;
		set<GraphVertex*, DijkstraSet> candidates;
		candidates.emplace(G[src]);
		while (!candidates.empty())
		{
			auto nearest = *candidates.begin();
			candidates.erase(candidates.begin());
			for (auto e : nearest->edges)
			{
				if (DijkstraRelax(nearest, e.dst, e.weight))
				{
					candidates.erase(e.dst);
					candidates.emplace(e.dst);
				}
			}
		}
	}
}