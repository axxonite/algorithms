#include "stdafx.h"

namespace Solutions
{
	struct DFSGraphVertex
	{
		vector<DFSGraphVertex*> edges;
		DFSGraphVertex* pred;
		int d, f;
	};

	void DFS(DFSGraphVertex* v, int& time)
	{
		v->d = time++;
		for (auto e : v->edges)
			if (e->d == 0)
				e->pred = v, DFS(e, time);
		v->f = time++;
	}

	void DFS(vector<DFSGraphVertex*> g)
	{
		int time = 0;
		for (auto v : g)
			if (v->d == 0)
				DFS(v, time);
	}
}