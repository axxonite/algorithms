#include "stdafx.h"
#include "..\..\Solutions\Data Structures\DisjointSet_solution.h"

#define TEST 1

struct KruskalGraphVertex;

struct Edge
{
  KruskalGraphVertex *src, *dest;
  double weight;

  bool operator < (const Edge& rhs) const {
    return weight < rhs.weight;
  }
};

struct KruskalGraphVertex : Solutions::SetElem
{
  vector<shared_ptr<Edge>> edges;
};

unordered_set<shared_ptr<Edge>> MstKruskal(vector<shared_ptr<KruskalGraphVertex>> g)
{
  unordered_set<shared_ptr<Edge>> result;
  unordered_set<shared_ptr<Edge>> edges;
  for (auto v : g)
  {
    Solutions::DisjointSet::MakeSet(v.get());
    for (auto e : v->edges)
      edges.emplace(e);
  }
  vector<shared_ptr<Edge>> sortedEdges(edges.begin(), edges.end());
  sort(sortedEdges.begin(), sortedEdges.end());
  for (auto e : edges)
  {
    if (Solutions::DisjointSet::FindSet(e->src) != Solutions::DisjointSet::FindSet(e->dest)) {
      result.emplace(e);
      Solutions::DisjointSet::Union(e->src, e->dest);
    }
  }
  return result;
}

#pragma region Test

shared_ptr<Edge> AddEdge(Edge edge)
{
  auto ptr = make_shared<Edge>(edge);
  ptr->src->edges.emplace_back(ptr);
  ptr->dest->edges.emplace_back(ptr);
  return ptr;
}

void MstKruskalTest()
{
#if TEST
  auto a = make_shared<KruskalGraphVertex>();
  auto b = make_shared<KruskalGraphVertex>();
  auto c = make_shared<KruskalGraphVertex>();
  auto d = make_shared<KruskalGraphVertex>();
  auto e = make_shared<KruskalGraphVertex>();
  auto f = make_shared<KruskalGraphVertex>();
  auto g = make_shared<KruskalGraphVertex>();
  auto h = make_shared<KruskalGraphVertex>();
  auto i = make_shared<KruskalGraphVertex>();

  auto goldenResult = unordered_set<shared_ptr<Edge>>();
  goldenResult.emplace(AddEdge(Edge{ a.get(), b.get(), 4 }));
  AddEdge(Edge{ a.get(), h.get(), 8 });
  goldenResult.emplace(AddEdge(Edge{ b.get(), c.get(), 8 }));
  AddEdge(Edge{ b.get(), h.get(), 11 });
  goldenResult.emplace(AddEdge(Edge{ c.get(), d.get(), 7 }));
  goldenResult.emplace(AddEdge(Edge{ c.get(), i.get(), 2 }));
  goldenResult.emplace(AddEdge(Edge{ c.get(), f.get(), 4 }));
  goldenResult.emplace(AddEdge(Edge{ d.get(), e.get(), 9 }));
  AddEdge(Edge{ d.get(), f.get(), 14 });
  AddEdge(Edge{ e.get(), f.get(), 10 });
  goldenResult.emplace(AddEdge(Edge{ f.get(), g.get(), 2 }));
  AddEdge(Edge{ g.get(), i.get(), 6 });
  goldenResult.emplace(AddEdge(Edge{ g.get(), h.get(), 1 }));

  auto result = MstKruskal(vector<shared_ptr<KruskalGraphVertex>>({a, b, c, d, e, f, g, h, i}));
  assert(result.size() == 7);
  for (auto edge : goldenResult)
    assert(result.count(edge));
#endif
}

#pragma endregion