// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"
#include "GraphVertex.h"

namespace Solutions
{
vector<vector<bool>> TransitiveClosure(vector<GraphVertex*> vertices)
{
	vector<vector<bool>> result(vertices.size(), vector<bool>(vertices.size(), false));
    
	// Mark the existing connect vertices.
    for (auto v : vertices)
    {
		result[v->Index()][v->Index()] = true;
      	for (auto e : v->edges)
        	result[v->Index()][e.dst->Index()] = true;
    }

    // DP
    // If there is a path from a src vertex to a mid vertex, and there is a path from the mid vertex to the dest vertex, then there is a path from src to dest.
    // In other words, pick a midpoint. All source vertices that pass through this midpoint have a path to all the destination vertices reachable from the midpoint.
    for (int mid = 0; mid < result.size(); ++mid)
    	for (int src = 0; src < result.size(); ++src)
        	if (result[src][mid])
          		for (int dst = 0; dst < result.size(); ++dst)
            		if (result[mid][dst])
              			result[src][dst] = true;
    return result;
}

}