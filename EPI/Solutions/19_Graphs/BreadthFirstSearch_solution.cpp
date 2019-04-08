#include "stdafx.h"

namespace Solutions
{
#include "stdafx.h"

  struct BFSGraphVertex
  {
    vector<BFSGraphVertex*> edges;
    int dist = -1;
    int stage = 0;
    BFSGraphVertex* pred = nullptr;
  };

  void BFS(BFSGraphVertex* v)
  {
    queue<BFSGraphVertex*> q;
    v->dist = 0;
    q.emplace(v);
    while (!q.empty())
    {
      auto cur = q.front();
      q.pop();
      cur->stage = 1;
      for (auto e : cur->edges)
        if (e->stage == 0)
        {
          e->pred = v;
          e->dist = v->dist + 1;
          e->stage = 1;
          q.emplace(e);
        }
      cur->stage = 2;
    }
  }

  void BFS(vector<BFSGraphVertex*> g)
  {
    for (auto v : g)
      if (v->stage == 0)
        BFS(v);
  }
}