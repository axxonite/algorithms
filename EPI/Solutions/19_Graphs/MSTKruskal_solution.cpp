#include "stdafx.h"
#include "Solutions/Data Structures/DisjointSet_solution.h"

namespace Solutions
{
	struct KruskalGraphVertex;

	struct Edge
	{
		KruskalGraphVertex *src, *dest;
		int weight;

	};

	struct KruskalGraphVertex : Solutions::SetElem
	{
		char data;
		vector<shared_ptr<Edge>> edges;
	};

	struct EdgeSort
	{
		bool operator () (const shared_ptr<Edge>& a, const shared_ptr<Edge>& b) const
		{
			return a->weight < b->weight || (a->weight == b->weight && a.get() < b.get());
		}
	};

	set<shared_ptr<Edge>> MstKruskal(vector<shared_ptr<KruskalGraphVertex>> g)
	{
		set<shared_ptr<Edge>> result;
		// Order all edges by weight, add each vertex to its own disjoint set.
		set<shared_ptr<Edge>, EdgeSort> sortedEdges;
		for (auto v : g)
		{
			Solutions::DisjointSet::MakeSet(v);
			for (auto e : v->edges)
				sortedEdges.insert(e);
		}
		for (auto e : sortedEdges)
		{
			// Look at vertices at each end of the edges (sorted by weight), merge them into the same set if they're not already merged
			// If two vertices could be merged through multiple edges, this ensures we are only merging them through the edge with the smallest weight, and we don't merge them merge than once.
			if (Solutions::DisjointSet::FindSet(e->src) != Solutions::DisjointSet::FindSet(e->dest)) {
				// Add the corresponding edge to the MST.
				result.insert(e);
				Solutions::DisjointSet::Union(e->src, e->dest);
			}
		}
		return result;
	}
}