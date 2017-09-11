// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	struct GraphVertex
	{
		int d = -1;
		vector<GraphVertex*> edges;
	};

	bool BFS(GraphVertex* s)
	{
		s->d = 0;
		queue<GraphVertex*> q;
		q.emplace(s);

		while (!q.empty())
		{
			for (GraphVertex*& t : q.front()->edges)
			{
				if (t->d == -1)
				{ // Unvisited vertex.
					t->d = q.front()->d + 1;
					q.emplace(t);
				}
				else if (t->d == q.front()->d)
					return false;
			}
			q.pop();
		}
		return true;
	}
	
	bool IsAnyPlacementFeasible(vector<GraphVertex>& g)
	{
		for (GraphVertex& v : g)
		{
			if (v.d == -1 && !BFS(&v))
				return false;
		}
		return true;
	}
}
