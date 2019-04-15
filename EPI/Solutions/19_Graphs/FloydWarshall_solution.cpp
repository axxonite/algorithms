// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
  void FloydMarshall(vector<vector<int>>& g)
  {
    for (int mid = 0; mid < g.size(); ++mid)
      for (int src = 0; src < g.size(); ++src)
        if (g[src][mid] != numeric_limits<int>::max())
          for (int dst = 0; dst < g.size(); ++dst)
            if (g[mid][dst] != numeric_limits<int>::max())
              g[src][dst] = min(g[src][dst], g[src][mid] + g[mid][dst]);
  }
}