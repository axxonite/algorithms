#include "stdafx.h"
#include "GraphVertex.h"

namespace Solutions
{
// Kosajaru's algorithm.

  void StronglyConnectedComponentsDFS(GraphVertex* src, vector<GraphVertex*>& DFSByFinishTime)
  {
    // Build transposed edges and record nodes by reverse order of finish times.
    src->start = 0;
    for (auto e : src->edges)
    {
      if (e.dst->start == -1) 
        StronglyConnectedComponentsDFS(e.dst, DFSByFinishTime);
      e.dst->transposedEdges.push_back(Edge{ src, e.weight });
    }
    DFSByFinishTime.push_back(src);
  }

  void StronglyConnectedComponentsDFS2(GraphVertex* src, unordered_set<GraphVertex*>& result)
  {
    // Gather strongly connected component vertices.
    src->start2 = 0;
    result.insert(src);
    for (auto e : src->transposedEdges)
    {
      if (e.dst->start2 == -1)
        StronglyConnectedComponentsDFS2(e.dst, result);
    }
  }

  vector<unordered_set<GraphVertex*>> StronglyConnectedComponents(vector<shared_ptr<GraphVertex>> G)
  {
    vector<unordered_set<GraphVertex*>> result;
    vector<GraphVertex*> DFSByFinishTime;
    for (auto v : G)
      if (v->start == -1)
        StronglyConnectedComponentsDFS(v.get(), DFSByFinishTime);

    for (int i = DFSByFinishTime.size() - 1; i >= 0; --i) {
      if (DFSByFinishTime[i]->start2 == -1)
      {
        result.push_back(unordered_set<GraphVertex*>()); // Insert an empty set
        StronglyConnectedComponentsDFS2(DFSByFinishTime[i], result.back());
      }
    }
    return result;
  }
}