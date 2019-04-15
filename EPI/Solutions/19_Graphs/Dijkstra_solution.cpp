#include "stdafx.h"

#define TEST 1

namespace Solutions
{
	struct DijkstraGraphVertex;

	struct Edge
	{
		DijkstraGraphVertex* dst;
		int weight;
	};

	struct DijkstraGraphVertex
	{
		int data;
		vector<Edge> edges;
		int dist = numeric_limits<int>::max();
		DijkstraGraphVertex* pred = nullptr;
	};

	struct DijkstraSet
	{
		bool operator () (const DijkstraGraphVertex* a, const DijkstraGraphVertex* b) const
		{
			return a->dist < b->dist || (a->dist == b->dist && a < b);
		}
	};

	bool Relax(DijkstraGraphVertex* u, DijkstraGraphVertex* v, int weight)
	{
		if (u->dist + weight < v->dist)
		{
			v->dist = u->dist + weight;
			v->pred = u;
			return true;
		}
		return false;
	}

	void Dijkstra(vector<DijkstraGraphVertex*> G, int src)
	{
		G[src]->dist = 0;
		set<DijkstraGraphVertex*, DijkstraSet> candidates;
		candidates.emplace(G[0]);
		while (!candidates.empty())
		{
			auto nearest = *candidates.begin();
			candidates.erase(candidates.begin());
			for (auto e : nearest->edges)
			{
				if (Relax(nearest, e.dst, e.weight))
				{
					candidates.erase(e.dst);
					candidates.emplace(e.dst);
				}
			}
		}
	}
}