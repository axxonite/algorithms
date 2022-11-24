#include "stdafx.h"
#include "Solutions/19_Graphs/TopologicalSort_solution.h"
#include "GraphVertex.h"

namespace Solutions
{
	void Relax(GraphVertex* u, GraphVertex* v, int weight)
	{
		if (u->dist < numeric_limits<int>::max() && u->dist + weight < v->dist)
		{
			v->dist = u->dist + weight;
			v->pred = u;
		}
	}

	// Does this work for graphs that are no DAGs?
	void SingleSourceShortestPath(vector<GraphVertex*> G, int src)
	{
		G[src]->dist = 0;
		auto topoSort = Solutions::TopologicalSort(G);
		for (auto v : topoSort)
			for (auto e : v->edges)
				Relax(v, e.dst, e.weight);
	}
}

#pragma endregion