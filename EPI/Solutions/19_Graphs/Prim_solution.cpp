#include "stdafx.h"
#include "GraphVertex.h"
#include "Problems/Data Structures/MSTEdge.h"

namespace Solutions
{
	typedef MSTEdge<GraphVertex> MSTPrimEdge;

	struct HashEdge
	{
		size_t operator () (const MSTPrimEdge& edge) const
		{
			return hash<size_t>()(edge.weight ^ hash<string>{}(edge.src->name) ^ hash<string>{}(edge.dest->name));
		}
	};

	struct PrimSet
	{
		bool operator () (const GraphVertex* a, const GraphVertex* b) const
		{
			return a->dist < b->dist || (a->dist == b->dist && a->name < b->name);
		}
	};

	unordered_set<MSTPrimEdge, HashEdge> Prim(vector<shared_ptr<GraphVertex>> g, int root)
	{
		unordered_set<MSTPrimEdge, HashEdge> result;
		g[root]->dist = 0;
		set<GraphVertex*, PrimSet> candidates;
    // This is basically Dijkstra.
		for (const auto& v : g)
			candidates.emplace(v.get());
    // Let A be a subset of a minimum spanning tree for G. A will start with the root vertex.
    // We build a minimum spanning tree edge by edge. When a vertex has a predecessor, it is considered
    // to be part of a subset of the minimum spanning tree.
    while (!candidates.empty())
		{
      // add the lightest edge to the minimum spanning tree.
      auto best = *candidates.begin();
			candidates.erase(candidates.begin());
			for (auto e : best->edges)
			{
				// This is similar to a Dijkstra heuristic.
				// Check that the destination is not already in A, and that the weight of the current edge is lower than the lowest weight found going to that vertex thus far.
				if (candidates.count(e.dst) && e.weight < e.dst->dist)
				{
          // update the lightest edge going to the destination vertex, and re-sort the set of candidates.
				  candidates.erase(e.dst);
					e.dst->pred = best;
					e.dst->dist = e.weight;
					candidates.emplace(e.dst);
				}
			}
		}
		for (const auto& v : g)
		{
			if (v->pred)
			{
				auto edge = MSTPrimEdge{ v.get(), v->pred, v->dist };
				result.emplace(edge);
			}
		}
		return result;
	}
}