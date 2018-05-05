// Copyright(c) 2015 Elements of Programming Interviews.All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	struct DistanceWithFewestEdges
	{
		int distance, minNumEdges;
		bool operator < (const DistanceWithFewestEdges& rhs) const
		{
			return distance < rhs.distance || (distance == rhs.distance && minNumEdges < rhs.minNumEdges);
		}
	};

	struct DijkstraGraphVertex
	{
		DistanceWithFewestEdges distanceWithFewestEdges = DistanceWithFewestEdges{ numeric_limits<int>::max(), 0 };

		struct VertexWithDistance
		{
			DijkstraGraphVertex& vertex;
			int distance;
		};
		vector<VertexWithDistance> edges;
		int id;  // The id of this vertex.
		const DijkstraGraphVertex* pred = nullptr;  // The predecessor in the shortest path.
	};

	// This is a standard Dijkstra implementation with the added edge count constraint.
	// More practice is required to nail down the Dijkstra implementation right. "Tricky" keyword.
	void DijkstraShortestPath(DijkstraGraphVertex* s, const DijkstraGraphVertex* t)
	{
		s->distanceWithFewestEdges = { 0, 0 }; // initialize source.
											   // set up an ordered node set with the right comparison function.
		set<DijkstraGraphVertex*, function<bool(DijkstraGraphVertex*, DijkstraGraphVertex*)>> nodeSet(
			[](const DijkstraGraphVertex* a, DijkstraGraphVertex* b) -> bool { return a->distanceWithFewestEdges < b->distanceWithFewestEdges; });
		nodeSet.emplace(s); // add source.
		while (!nodeSet.empty())
		{
			DijkstraGraphVertex* u = *nodeSet.begin(); // node with shortest distance and edges.
			if (u->id == t->id) // if this is the destination, then we've found our shortest path.
				break;
			nodeSet.erase(nodeSet.begin());

			for (auto& v : u->edges) // test all edges from the candidate for the shortest path.
			{
				// is this a shorter path?
				DistanceWithFewestEdges cur = { u->distanceWithFewestEdges.distance + v.distance, u->distanceWithFewestEdges.minNumEdges + 1 };
				if (cur < v.vertex.distanceWithFewestEdges)
				{
					nodeSet.erase(&v.vertex);
					// yes, then update it as a thing and update the set.
					v.vertex.pred = u;
					v.vertex.distanceWithFewestEdges = cur;
					nodeSet.emplace(&v.vertex);
				}
			}
		}
	}
}