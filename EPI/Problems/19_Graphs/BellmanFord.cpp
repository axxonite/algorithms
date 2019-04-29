#include "stdafx.h"
#include "GraphVertex.h"

#define TEST 0

bool BellmanFord(vector<GraphVertex*> G, int src)
{

	return true;
}

#pragma region Test

void BellmanFordTest()
{
#if TEST
	unordered_map<string, shared_ptr<GraphVertex>> G;
  G["s"] = make_shared<GraphVertex>(GraphVertex{ "s" });
  G["t"] = make_shared<GraphVertex>(GraphVertex{ "t" });
  G["x"] = make_shared<GraphVertex>(GraphVertex{ "x" });
  G["y"] = make_shared<GraphVertex>(GraphVertex{ "y" });
  G["z"] = make_shared<GraphVertex>(GraphVertex{ "z" });

  G["s"]->edges.emplace_back(Edge{ G["t"].get(), 6 });
  G["s"]->edges.emplace_back(Edge{ G["y"].get(), 7 });
  G["t"]->edges.emplace_back(Edge{ G["x"].get(), 5 });
  G["t"]->edges.emplace_back(Edge{ G["y"].get(), 8 });
  G["t"]->edges.emplace_back(Edge{ G["z"].get(), -4 });
  G["x"]->edges.emplace_back(Edge{ G["t"].get(), -2 });
  G["y"]->edges.emplace_back(Edge{ G["x"].get(), -3 });
  G["y"]->edges.emplace_back(Edge{ G["z"].get(), 9 });
  G["z"]->edges.emplace_back(Edge{ G["s"].get(), 2 });
  G["z"]->edges.emplace_back(Edge{ G["x"].get(), 7 });

	vector< GraphVertex*> v;
  v.emplace_back(G["s"].get());
  v.emplace_back(G["t"].get());
  v.emplace_back(G["x"].get());
  v.emplace_back(G["y"].get());
  v.emplace_back(G["z"].get());
	assert(BellmanFord(v, 0));
  assert(G["s"]->dist == 0);
  assert(G["t"]->dist == 2);
  assert(G["x"]->dist == 4);
  assert(G["y"]->dist == 7);
  assert(G["z"]->dist == -2);
#endif
}

#pragma endregion