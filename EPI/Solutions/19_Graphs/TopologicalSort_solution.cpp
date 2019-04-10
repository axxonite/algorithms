#include "stdafx.h"

namespace Solutions
{
	struct TopoGraphVertex
	{
		string name;
		int stage = 0;
		vector<shared_ptr<TopoGraphVertex>> edges;
	};

	void TopologicalSort(TopoGraphVertex* v, list<TopoGraphVertex*>& result)
	{
		v->stage = 1;
		for (auto e : v->edges)
		{
			if (e->stage == 0)
				TopologicalSort(e.get(), result);
		}
		result.emplace_front(v);
	}

	list<TopoGraphVertex*> TopologicalSort(vector<TopoGraphVertex*>& g)
	{
		list<TopoGraphVertex*> result;
		for (auto v : g)
			if (v->stage == 0)
				TopologicalSort(v, result);
		return result;
	}
}