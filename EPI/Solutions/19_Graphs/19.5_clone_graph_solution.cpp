// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"
#include "GraphVertex.h"
#include "19.5_clone_graph_solution.h"

namespace Solutions
{
	GraphVertex* CloneGraph(GraphVertex* G)
	{
		// this mapping will map the old vertex to the new vertex
		unordered_map<GraphVertex*, GraphVertex*> mapping;
		mapping[G] = new GraphVertex{ G->name };
		// the queue can hold either the old or the new vertex. The implementation with the new vertex seems a little more intuitive, though
		// the implementation with the old vertex is a bit shorter.
		queue<GraphVertex*> q;
		q.emplace(G);
		while (!q.empty())
		{
			auto c = q.front();
			q.pop();
			for (Edge e : c->edges)
			{
				if (mapping.find(e.dst) == mapping.end())
				{
					// We map new vertices that don't have any children in them yet.
					mapping[e.dst] = new GraphVertex{ e.dst->name };
					q.emplace(e.dst);
				}
				// We look up the mapping to start from the old vertex and add the new edges to the new vertex.
				mapping[c]->edges.emplace_back(Edge{ mapping[e.dst], e.weight });
			}
		}
		return mapping[G];
	}

	GraphVertex* CloneGraph(GraphVertex* G, unordered_map<GraphVertex*, GraphVertex*>& mapping)
	{
		auto it = mapping.find(G);
		if (it != mapping.end())
			return it->second;
		GraphVertex* clone = new GraphVertex{ G->name };
		mapping[G] = clone;
		for (auto e : G->edges)
			clone->edges.emplace_back(Edge{ CloneGraph(e.dst, mapping), e.weight });
		return clone;
	}

	GraphVertex* CloneGraph2(GraphVertex* G)
	{
		unordered_map<GraphVertex*, GraphVertex*> mapping;
		return CloneGraph(G, mapping);
	}

	vector<GraphVertex*> CloneGraph(vector<GraphVertex*> G)
	{
		vector<GraphVertex*> result;
		unordered_map<GraphVertex*, GraphVertex*> mapping;
		for (auto g : G)
		{
			if (mapping.find(g) == mapping.end())
				CloneGraph(g, mapping);
		}

		for (auto pair : mapping)
			result.emplace_back(pair.second);
		return result;
	}
}