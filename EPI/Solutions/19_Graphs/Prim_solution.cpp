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
		while (!candidates.empty())
		{
			// take the candidate with the lightest edge going to it, and include the lightest edge
			// going to any of its neighbors.
			auto best = *candidates.begin();
			candidates.erase(candidates.begin());
			for (auto e : best->edges)
			{
				// This is essentially a Dijkstra heuristic.
				// check that we haven't processed the destination yet, and that the weight of the current edge is lower than the assigned weight of the destination vertex.
				// e.dst->dist contains the weight of the lowest weight edge that connects to e.dst.
				if (candidates.count(e.dst) && e.weight < e.dst->dist)
				{
					candidates.erase(e.dst);
					// the predecessor keeps track of which edge going into the e.dst vertex would be the lowest weight.
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