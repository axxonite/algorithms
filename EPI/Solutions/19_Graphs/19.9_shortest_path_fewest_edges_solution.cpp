// Copyright(c) 2015 Elements of Programming Interviews.All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	struct DijkstraGraphVertex
	{
		struct DistanceWithFewestEdges
		{
			int distance, minNumEdges;
		};
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

	struct Comp
	{
		bool operator ()(const DijkstraGraphVertex* lhs, const DijkstraGraphVertex* rhs) const
		{
			return lhs->distanceWithFewestEdges.distance < rhs->distanceWithFewestEdges.distance ||
			(lhs->distanceWithFewestEdges.distance == rhs->distanceWithFewestEdges.distance &&
				lhs->distanceWithFewestEdges.minNumEdges < rhs->distanceWithFewestEdges.minNumEdges);
		}
	};

	// This is a standard Dijkstra implementation with the added edge count constraint.
	// More practice is required to nail down the Dijkstra implementation right. "Tricky" keyword.
	void DijkstraShortestPath(DijkstraGraphVertex* s, const DijkstraGraphVertex* t)
	{
		// Start with s at distance 0 and add it to the node set.
		s->distanceWithFewestEdges = { 0, 0 };
		set<DijkstraGraphVertex*, Comp> nodeSet; // Note that the nodeset is ordered such that the shortest paths appear first.
		nodeSet.emplace(s);

		while (!nodeSet.empty())
		{
			DijkstraGraphVertex* u = *nodeSet.begin();
			if (u->id == t->id)
				break; // we've reached our destination.
			nodeSet.erase(nodeSet.begin());

			// expand out from the current vertex u.
			for (auto& v : u->edges)
			{
				int dist = u->distanceWithFewestEdges.distance + v.distance;
				int numEdges = u->distanceWithFewestEdges.minNumEdges + 1;
				// Check if, going from u to v, we've found a shorter path to s.
				if (v.vertex.distanceWithFewestEdges.distance > dist ||
					(v.vertex.distanceWithFewestEdges.distance == dist && v.vertex.distanceWithFewestEdges.minNumEdges > numEdges))
				{
					// If so, erase our old record for v from the set (if it exists in the set), and update it with one with updated shortest path info.
					nodeSet.erase(&v.vertex);
					v.vertex.pred = u; // now the shortest path to v comes from u
					v.vertex.distanceWithFewestEdges = { dist, numEdges }; // and the distance is v's path length + the edge length to v->u
					nodeSet.emplace(&v.vertex);
				}
			}
		}
	}
}
