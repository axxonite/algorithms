#pragma once

#include <string>
#include <list>
#include <vector>

using namespace std;

namespace Solutions
{
	struct TopoGraphVertex;

	struct Edge
	{
		TopoGraphVertex* dst;
		int weight;
	};

	struct TopoGraphVertex
	{
		char name;
		int stage = 0;
		int dist = numeric_limits<int>::max();
		TopoGraphVertex* pred = nullptr;
		vector<Edge> edges;
	};

	inline void TopologicalSort(TopoGraphVertex* v, list<TopoGraphVertex*>& result)
	{
		v->stage = 1;
		for (auto e : v->edges)
		{
			if (e.dst->stage == 0)
				TopologicalSort(e.dst, result);
		}
		result.emplace_front(v);
	}

	inline list<TopoGraphVertex*> TopologicalSort(vector<TopoGraphVertex*>& g)
	{
		list<TopoGraphVertex*> result;
		for (auto v : g)
			if (v->stage == 0)
				TopologicalSort(v, result);
		return result;
	}
}