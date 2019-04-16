#include "stdafx.h"
#include "GraphVertex.h"

namespace Solutions
{
  struct SCCGraphVertex : GraphVertex
  {
    int start2 = -1;
    vector<Edge> transposedEdges;
  };

  void StronglyConnectedComponentsDFS(SCCGraphVertex* v, int& time)
  {
    v->start = time++;
    for (auto e : v->edges)
    {
      SCCGraphVertex* edgeVertex = (SCCGraphVertex*)e.dst;
      if (edgeVertex->start == -1)
        StronglyConnectedComponentsDFS(edgeVertex, time);
      edgeVertex->transposedEdges.emplace_back(Edge{ v, e.weight });
    }
    v->finish = time++;
  }

  bool SortEdges(const Edge& a, const Edge& b)
  {
    return a.dst->finish > b.dst->finish;
  }

  void StronglyConnectedComponentsDFS2(SCCGraphVertex* v, int& time, unordered_set<SCCGraphVertex*>& result)
  {
    v->start2 = time++;
    result.emplace(v);
    sort(v->transposedEdges.begin(), v->transposedEdges.end(), SortEdges);
    for (auto e : v->transposedEdges)
    {
      SCCGraphVertex* edgeVertex = (SCCGraphVertex*)e.dst;
      if (edgeVertex->start2 == -1)
        StronglyConnectedComponentsDFS2(edgeVertex, time, result);
    }
  }
  vector<unordered_set<SCCGraphVertex*>> StronglyConnectedComponents(vector<shared_ptr<SCCGraphVertex>> G)
  {
    vector<unordered_set<SCCGraphVertex*>> result;
    int time = 0;
    for (auto v : G)
      if (v->start == -1)
        StronglyConnectedComponentsDFS(v.get(), time);
    for (auto v : G)
    {
      if (v->start2 == -1)
      {
        result.emplace_back(unordered_set<SCCGraphVertex*>());
        StronglyConnectedComponentsDFS2(v.get(), time, result.back());
      }
    }
    return result;
  }
}