// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	struct GraphVertex
	{
		enum Color
		{
			white,
			gray,
			black
		} color = white;

		vector<GraphVertex*> edges;
	};

	bool HasCycle(GraphVertex* cur)
	{
		// Visiting a gray vertex means a cycle.
		if (cur->color == GraphVertex::gray)
			return true;

		cur->color = GraphVertex::gray; // mark current vertex as gray.
		// Traverse non-black neighbor vertices and check for cycles.
		for (GraphVertex*& next : cur->edges)
			if (next->color != GraphVertex::black && HasCycle(next))
				return true;
		cur->color = GraphVertex::black; // mark current vertex as black.
		return false;
	}

	bool IsDeadlocked(vector<GraphVertex>* G)
	{
		// Iterate over all white vertices and check for cycles.
		return any_of(begin(*G), end(*G), [](GraphVertex& vertex) { return vertex.color == GraphVertex::white && HasCycle(&vertex); });
	}
}
