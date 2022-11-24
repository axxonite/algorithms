#include "stdafx.h"
#include "GraphVertex.h"

namespace Solutions
{

  bool BellmanFordRelax(GraphVertex* u, GraphVertex* v, int weight)
  {
    // Relaxation step. Same as Dijkstra.
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
    // Go over every edge G.size() times, that's it.
    for (int i = 0; i < G.size() - 1; ++i)
    {
      for (auto v : G)
        for (auto e : v->edges)
          BellmanFordRelax(v, e.dst, e.weight);
    }
    // Then check for negative cycles.
    for (auto v : G)
      for (auto e : v->edges)
        if (BellmanFordRelax(v, e.dst, e.weight))
          return false;
    return true;
  }
}