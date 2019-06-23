#include "stdafx.h"
#include "GraphVertex.h"

void FindArticulationVertices(GraphVertex* v, int& time, vector<GraphVertex*>& result)
{
  v->start = time++;
  v->reachableAncestor = v; // assign initial reachable ancestor

  for (auto e : v->edges)
  {
    // say target of edge e is y
    // if y is discovered but not processed, and y is not the immediate parent of v, then we have a back edge.
    // if we have a back edge (aka. a "security cable") and y is higher up the tree than the current ERV.
    if (e.dst->start != -1 && e.dst->finish == -1 && v->pred != e.dst && e.dst->start < v->reachableAncestor->start)
      v->reachableAncestor = e.dst; // update ERV.

    // Perform DFS.
    if (e.dst->start == -1)
    {
      e.dst->pred = v;
      FindArticulationVertices(e.dst, time, result);
    }
  }

  if (v->pred) // if we have a parent.
  {
    if (v->reachableAncestor == v->pred && v->pred->pred != nullptr) // ERV is the parent of V and the parent of V is not the root.
      result.emplace_back(v->pred); // then parent of v is a parent articulation vertex.
    if (v->reachableAncestor == v) // ERV is self.
    {
      result.emplace_back(v->pred); // then parent of v is a bridge articlation vertex.
      if (!v->edges.empty()) // v is not a leaf.
        result.emplace_back(v); // then v is a bridge articulation vertex.
    }

    // update ERV for the parent
    if (v->pred->reachableAncestor->start > v->reachableAncestor->start)
      v->pred->reachableAncestor = v->reachableAncestor;
  }
  else if (v->edges.size() > 1) // v is the root and has two or more children.
    result.emplace_back(v); // v is a root articulation vertex

  v->finish = time++;
}

void FindArticulationVertices(vector<GraphVertex*> g, vector<GraphVertex*>& result)
{
  int time = 0;
  for (auto v : g)
    if (v->start == -1)
      FindArticulationVertices(v, time, result);
}