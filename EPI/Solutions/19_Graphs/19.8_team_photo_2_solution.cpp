// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	struct TeamPhotoGraphVertex
	{
		vector<TeamPhotoGraphVertex*> edges;
		// Set max_distance = 0 to indicate unvisited vertex.
		int max_distance = 0;
	};

	// My solution is substantially different from the book solution in that:
	// * I don't compute an explicit topological ordering
	// * The distance value starts at 1 at the leaves and goes higher up in the tree, whereas the book does the reverse
	//
	// As far as I can tell, my solution is simpler, and produces a valid solution.
	void TopologicalSortAndDistance(TeamPhotoGraphVertex* g)
	{
		g->max_distance = 1;
		for (auto e : g->edges)
		{
			if (e->max_distance == 0)
				TopologicalSortAndDistance(e);
			if (e->max_distance + 1 > g->max_distance)
				g->max_distance = e->max_distance + 1;
		}
	}

	int FindLargestNumberTeams(vector<TeamPhotoGraphVertex>& g)
	{
		int largestDistance = 1;
		for (auto v : g)
		{
			if (v.max_distance == 0)
				TopologicalSortAndDistance(&v);
			largestDistance = max(largestDistance, v.max_distance);
		}
		return largestDistance;
	}
}