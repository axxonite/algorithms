// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"
#include "GraphVertex.h"

namespace Solutions
{
  vector<vector<bool>> TransitiveClosure(vector<GraphVertex*> vertices)
  {
    vector<vector<bool>> result(vertices.size(), vector<bool>(vertices.size(), false));
    for (auto v : vertices)
    {
      result[v->Index()][v->Index()] = true;
      for (auto e : v->edges)
        result[v->Index()][e.dst->Index()] = true;
    }

    for (int mid = 0; mid < result.size(); ++mid)
      for (int src = 0; src < result.size(); ++src)
        if (result[src][mid])
          for (int dst = 0; dst < result.size(); ++dst)
            if (result[mid][dst])
              result[src][dst] = result[src][dst] || (result[src][mid] && result[mid][dst]);
    return result;
  }
}