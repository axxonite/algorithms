#include "stdafx.h"
#include "GraphVertex.h"

namespace Solutions
{
	void FindArticulationVertices(GraphVertex* v, int& time, vector<GraphVertex*>& result)
	{
		v->start = time++;
		v->reachableAncestor = v;
		for (auto e : v->edges)
		{
			if (e.dst->dist == 0)
			{
				// tree edge
				e.dst->pred = v;
				v->degree++;
				FindArticulationVertices(e.dst, time, result);
			}
			else
			{
				// back edge
				if (v->pred != e.dst && e.dst->start < v->reachableAncestor->start)
					v->reachableAncestor = e.dst;
			}
		}
		v->finish = time++;

		if (!v->pred)
		{
			// Root cut-nodes
			// If the root of the DFS tree has two or more children, it must be an articulation vertex.
			// No edges from the subtree of the second child can possibly connect to the subtree of the first child.
			if (v->degree > 1)
				result.emplace_back(v); // root articulation vertex.
			return;
		}

		// If the earliest reachable vertex from v is the parent of v, then deleting the parent must sever v from the 
		// tree unless the parent is the root.
		if (v->reachableAncestor == v->pred && v->pred->pred)
			result.emplace_back(v->pred); // parent articulation vertex.

		// If the earliest reachable vertex from v is v, then deleting the single edge from the parent to v disconnects
		// the graph. Clearly the parent of v must be an articulation vertex since it cuts v from the graph. Vertex v is
		// also an articulation vertex unless it is a leaf of the DFS tree.
		if (v->reachableAncestor == v)
		{
			result.emplace_back(v->pred);
			if (v->degree > 0)
				result.emplace_back(v); // bridge articulation vertex.
		}

		if (v->reachableAncestor->start < v->reachableAncestor->pred->start)
			v->pred->reachableAncestor = v->reachableAncestor;
	}

	void FindArticulationVertices(vector<GraphVertex*> g, vector<GraphVertex*>& result)
	{
		int time = 0;
		for (auto v : g)
			if (v->start == 0)
				FindArticulationVertices(v, time, result);
	}
}