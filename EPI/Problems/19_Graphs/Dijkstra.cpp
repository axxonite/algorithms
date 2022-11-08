#include "stdafx.h"
#include "GraphVertex.h"
#include <set>

// #define TEST

void Dijkstra(vector<GraphVertex*> G, int src)
{
}

#pragma region Test

void DijkstraTest()
{
#ifdef TEST
  unordered_map<string, shared_ptr<GraphVertex>> G;
  auto s = make_shared<GraphVertex>("s");
  auto t = make_shared<GraphVertex>("t");
  auto x = make_shared<GraphVertex>("x");
  auto y = make_shared<GraphVertex>("y");
  auto z = make_shared<GraphVertex>("z");

  s->edges.emplace_back(t.get(), 10);
  s->edges.emplace_back(y.get(), 5);
  t->edges.emplace_back(x.get(), 1);
  t->edges.emplace_back(y.get(), 2);
  x->edges.emplace_back(z.get(), 4);
  y->edges.emplace_back(t.get(), 3);
  y->edges.emplace_back(x.get(), 9);
  y->edges.emplace_back(z.get(), 2);
  z->edges.emplace_back(s.get(), 7);
  z->edges.emplace_back(x.get(), 6);

  vector<GraphVertex*> v;
  v.push_back(s.get());
  v.push_back(t.get());
  v.push_back(x.get());
  v.push_back(y.get());
  v.push_back(z.get());
  Dijkstra(v, 0);
  assert(s->dist == 0);
  assert(t->dist == 8);
  assert(x->dist == 9);
  assert(y->dist == 5);
  assert(z->dist == 7);
#endif
}

#pragma endregion