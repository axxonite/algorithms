#include "stdafx.h"
#include "..\..\Solutions\19_Graphs\TopologicalSort_solution.h"

namespace Solutions
{
	void Relax(Solutions::TopoGraphVertex* u, Solutions::TopoGraphVertex* v, int weight)
	{
		if (u->dist + weight < v->dist)
		{
			v->dist = u->dist + weight;
			v->pred = u;
		}
	}

	// todo make a shared vertex type for all graphs.
	void SingleSourceShortestPath(vector<Solutions::TopoGraphVertex*> G, int src)
	{
		G[src]->dist = 0;
		auto topoSort = Solutions::TopologicalSort(G);
		for (auto v : topoSort)
			for (auto e : v->edges)
				Relax(v, e.dst, e.weight);
	}
}

#pragma endregion