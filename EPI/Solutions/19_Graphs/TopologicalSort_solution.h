#pragma once

#include <string>
#include <list>
#include <vector>
#include "GraphVertex.h"

using namespace std;

namespace Solutions
{

	inline void TopologicalSort(GraphVertex* v, list<GraphVertex*>& result)
	{
		v->stage = 1;
		for (auto e : v->edges)
		{
			if (e.dst->stage == 0)
				TopologicalSort(e.dst, result);
		}
		result.emplace_front(v);
	}

	inline list<GraphVertex*> TopologicalSort(vector<GraphVertex*>& g)
	{
		list<GraphVertex*> result;
		for (auto v : g)
			if (v->stage == 0)
				TopologicalSort(v, result);
		return result;
	}
}