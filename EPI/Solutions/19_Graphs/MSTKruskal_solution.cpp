#include "stdafx.h"
#include "..\..\Solutions\Data Structures\DisjointSet_solution.h"

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
			return hash<int>()(edge->src->data ^ edge->dest->data);
		}
	};

	bool SortEdges(const shared_ptr<Edge>& a, const shared_ptr<Edge>& b)
	{
		return a->weight < b->weight;
	}

	unordered_set<shared_ptr<Edge>, HashEdge> MstKruskal(vector<shared_ptr<KruskalGraphVertex>> g)
	{
		unordered_set<shared_ptr<Edge>, HashEdge> result;
		unordered_set<shared_ptr<Edge>, HashEdge> edges;
		for (auto v : g)
		{
			Solutions::DisjointSet::MakeSet(v);
			for (auto e : v->edges)
				edges.emplace(e);
		}
		vector<shared_ptr<Edge>> sortedEdges(edges.begin(), edges.end());
		sort(sortedEdges.begin(), sortedEdges.end(), SortEdges);
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