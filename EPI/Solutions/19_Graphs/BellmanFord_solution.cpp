#include "stdafx.h"
#include "GraphVertex.h"

namespace Solutions
{

  bool BellmanFordRelax(GraphVertex* u, GraphVertex* v, int weight)
  {
    if (u->dist < numeric_limits<int>::max() && u->dist + weight < v->dist)
    {
      v->dist = u->dist + weight;
      v->pred = u;
      return true;
    }
    return false;
  }

  bool BellmanFord(vector<GraphVertex*> G, int src)
  {
    G[src]->dist = 0;
    for (int i = 0; i < G.size(); ++i)
    {
      for (auto v : G)
        for (auto e : v->edges)
          BellmanFordRelax(v, e.dst, e.weight);
    }
    for (auto v : G)
      for (auto e : v->edges)
        if (BellmanFordRelax(v, e.dst, e.weight))
          return false;
    return true;
  }
}