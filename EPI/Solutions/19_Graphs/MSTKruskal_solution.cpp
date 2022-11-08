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

	struct HashEdge
	{
		size_t operator () (const shared_ptr<Edge>& edge) const
		{
			return hash<size_t>()(reinterpret_cast<size_t>(edge.get()));
		}

		bool operator () (const shared_ptr<Edge>& a, const shared_ptr<Edge>& b) const
		{
			return a->weight < b->weight || (a->weight == b->weight && a.get() < b.get());
		}
	};

	unordered_set<shared_ptr<Edge>, HashEdge> MstKruskal(vector<shared_ptr<KruskalGraphVertex>> g)
	{
		unordered_set<shared_ptr<Edge>, HashEdge> result;
		set<shared_ptr<Edge>, HashEdge> sortedEdges;
		for (auto v : g)
		{
			Solutions::DisjointSet::MakeSet(v);
			for (auto e : v->edges)
				sortedEdges.emplace(e);
		}
		for (auto e : sortedEdges)
		{
			if (Solutions::DisjointSet::FindSet(e->src) != Solutions::DisjointSet::FindSet(e->dest)) {
				result.emplace(e);
				Solutions::DisjointSet::Union(e->src, e->dest);
			}
		}
		return result;
	}
}