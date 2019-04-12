#include "stdafx.h"

namespace Solutions
{
  struct BFGraphVertex;

  struct Edge
  {
    BFGraphVertex* dst;
    int weight;
  };

  struct BFGraphVertex
  {
    int data;
    vector<Edge> edges;
    int dist = numeric_limits<int>::max();
    BFGraphVertex* pred = nullptr;
  };

  bool Relax(BFGraphVertex* u, BFGraphVertex* v, int weight)
  {
    if (u->dist + weight < v->dist)
    {
      v->dist = u->dist + weight;
      v->pred = u;
      return true;
    }
    return false;
  }

  bool BellmanFord(vector<BFGraphVertex*> G, int src)
  {
    G[src]->dist = 0;
    for (int i = 0; i < G.size(); ++i)
    {
      for (auto v : G)
        for (auto e : v->edges)
          Relax(v, e.dst, e.weight);
    }
    for (auto v : G)
      for (auto e : v->edges)
        if (Relax(v, e.dst, e.weight))
          return false;
    return true;
  }
}