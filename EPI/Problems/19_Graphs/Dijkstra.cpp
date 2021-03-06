#include "stdafx.h"
#include "GraphVertex.h"

// #define TEST

void Dijkstra(vector<GraphVertex*> G, int src)
{
}

#pragma region Test

void DijkstraTest()
{
#ifdef TEST
  unordered_map<string, shared_ptr<GraphVertex>> G;
  G["s"] = make_shared<GraphVertex>(GraphVertex{ "s" });
  G["t"] = make_shared<GraphVertex>(GraphVertex{ "t" });
  G["x"] = make_shared<GraphVertex>(GraphVertex{ "x" });
  G["y"] = make_shared<GraphVertex>(GraphVertex{ "y" });
  G["z"] = make_shared<GraphVertex>(GraphVertex{ "z" });

  G["s"]->edges.emplace_back(Edge{ G["t"].get(), 10 });
  G["s"]->edges.emplace_back(Edge{ G["y"].get(), 5 });
  G["t"]->edges.emplace_back(Edge{ G["x"].get(), 1 });
  G["t"]->edges.emplace_back(Edge{ G["y"].get(), 2 });
  G["x"]->edges.emplace_back(Edge{ G["z"].get(), 4 });
  G["y"]->edges.emplace_back(Edge{ G["t"].get(), 3 });
  G["y"]->edges.emplace_back(Edge{ G["x"].get(), 9 });
  G["y"]->edges.emplace_back(Edge{ G["z"].get(), 2 });
  G["z"]->edges.emplace_back(Edge{ G["s"].get(), 7 });
  G["z"]->edges.emplace_back(Edge{ G["x"].get(), 6 });

  vector<GraphVertex*> v;
  v.emplace_back(G["s"].get());
  v.emplace_back(G["t"].get());
  v.emplace_back(G["x"].get());
  v.emplace_back(G["y"].get());
  v.emplace_back(G["z"].get());
  Dijkstra(v, 0);
  assert(G["s"]->dist == 0);
  assert(G["t"]->dist == 8);
  assert(G["x"]->dist == 9);
  assert(G["y"]->dist == 5);
  assert(G["z"]->dist == 7);
#endif
}

#pragma endregion