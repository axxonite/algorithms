// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"
#include "GraphVertex.h"

#define TEST 0

vector<vector<bool>> TransitiveClosure(vector<GraphVertex*> vertices)
{
  vector<vector<bool>> result(vertices.size(), vector<bool>(vertices.size(), false));
  return result;
}

void TransitiveClosureTest()
{
#if TEST

  unordered_map<string, shared_ptr<GraphVertex>> G;
  G["1"] = make_shared<GraphVertex>(GraphVertex{ "1" });
  G["2"] = make_shared<GraphVertex>(GraphVertex{ "2" });
  G["3"] = make_shared<GraphVertex>(GraphVertex{ "3" });
  G["4"] = make_shared<GraphVertex>(GraphVertex{ "4" });

  G["2"]->edges.emplace_back(Edge{ G["3"].get(), 1 });
  G["2"]->edges.emplace_back(Edge{ G["4"].get(), 1 });
  G["3"]->edges.emplace_back(Edge{ G["2"].get(), 1 });
  G["4"]->edges.emplace_back(Edge{ G["1"].get(), 1 });
  G["4"]->edges.emplace_back(Edge{ G["3"].get(), 1 });

  vector<GraphVertex*> v;
  v.emplace_back(G["1"].get());
  v.emplace_back(G["2"].get());
  v.emplace_back(G["3"].get());
  v.emplace_back(G["4"].get());
  auto result = TransitiveClosure(v);
  assert(result[0] == vector<bool>({ true, false, false, false }));
  assert(result[1] == vector<bool>({ true, true, true, true }));
  assert(result[2] == vector<bool>({ true, true, true, true }));
  assert(result[3] == vector<bool>({ true, true, true, true }));
#endif
}