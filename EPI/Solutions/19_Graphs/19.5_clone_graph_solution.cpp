// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	struct CloneGraphVertex
	{
		int label;
		vector<CloneGraphVertex*> edges;
	};

	CloneGraphVertex* CloneGraph( CloneGraphVertex* G )
	{
		// this mapping will map the old vertex to the new vertex
		unordered_map<CloneGraphVertex*, CloneGraphVertex*> mapping;
		mapping[G] = new CloneGraphVertex{ G->label };
		// the queue can hold either the old or the new vertex. The implementation with the new vertex seems a little more intuitive, though
		// the implementation with the old vertex is a bit shorter.
		queue<CloneGraphVertex*> q;
		q.emplace( G );
		while ( !q.empty() )
		{
			auto c = q.front();
			q.pop();
			for ( CloneGraphVertex* e : c->edges )
			{
				if ( mapping.find( e ) == mapping.end() )
				{
					// We map new vertices that don't have any children in them yet.
					mapping[e] = new CloneGraphVertex{ e->label };
					q.emplace( e );
				}
				// We look up the mapping to start from the old vertex and add the new edges to the new vertex.
				mapping[c]->edges.emplace_back( mapping[e] );
			}
		}
		return mapping[G];
	}
}