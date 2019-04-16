#include "stdafx.h"
#include "GraphVertex.h"

namespace Solutions
{
#include "stdafx.h"

  void BFS(GraphVertex* v)
  {
    queue<GraphVertex*> q;
    v->dist = 0;
    q.emplace(v);
    while (!q.empty())
    {
      auto cur = q.front();
      q.pop();
      cur->stage = 1;
      for (auto e : cur->edges)
        if (e.dst->stage == 0)
        {
          e.dst->pred = v;
          e.dst->dist = v->dist + 1;
          e.dst->stage = 1;
          q.emplace(e.dst);
        }
      cur->stage = 2;
    }
  }

  void BFS(vector<GraphVertex*> g)
  {
    for (auto v : g)
      if (v->stage == 0)
        BFS(v);
  }
}