#include "stdafx.h"
#include "..\..\Solutions\Data Structures\DisjointSet_solution.h"

#define TEST 0

struct KruskalGraphVertex;

struct Edge
{
	KruskalGraphVertex* src;
	KruskalGraphVertex* dest;
	int weight;

};

struct KruskalGraphVertex : Solutions::SetElem
{
	char data;
	vector<shared_ptr<Edge>> edges;
};

struct HashEdge
{
  size_t operator () (const shared_ptr<Edge>& edge) const
  {
    return hash<size_t>()(reinterpret_cast<size_t>(edge.get()));
  }
};

unordered_set<shared_ptr<Edge>, HashEdge> MstKruskal(vector<shared_ptr<KruskalGraphVertex>> g)
{
	unordered_set<shared_ptr<Edge>, HashEdge> result;
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
	a->data = 'a';
	b->data = 'b';
	c->data = 'c';
	d->data = 'd';
	e->data = 'e';
	f->data = 'f';
	g->data = 'g';
	h->data = 'h';
	i->data = 'i';

	auto goldenResult = unordered_set<shared_ptr<Edge>, HashEdge>();
	goldenResult.emplace(AddEdge(Edge{ a.get(), b.get(), 4 }));
  goldenResult.emplace(AddEdge(Edge{ c.get(), d.get(), 7 }));
  goldenResult.emplace(AddEdge(Edge{ c.get(), i.get(), 2 }));
  goldenResult.emplace(AddEdge(Edge{ c.get(), f.get(), 4 }));
  goldenResult.emplace(AddEdge(Edge{ d.get(), e.get(), 9 }));
  goldenResult.emplace(AddEdge(Edge{ g.get(), h.get(), 1 }));
  goldenResult.emplace(AddEdge(Edge{ f.get(), g.get(), 2 }));
  goldenResult.emplace(AddEdge(Edge{ a.get(), h.get(), 8 }));
  AddEdge(Edge{ b.get(), c.get(), 8 });
  AddEdge(Edge{ b.get(), h.get(), 11 });
	AddEdge(Edge{ d.get(), f.get(), 14 });
	AddEdge(Edge{ e.get(), f.get(), 10 });
  AddEdge(Edge{ g.get(), i.get(), 6 });
	AddEdge(Edge{ h.get(), i.get(), 7 });

	auto result = MstKruskal(vector<shared_ptr<KruskalGraphVertex>>({ a, b, c, d, e, f, g, h, i }));
	assert(result.size() == 8);
	auto weight = 0;
	for (auto edge : result)
		weight += edge->weight;
	assert(weight == 37);
	for (auto edge : goldenResult)
		assert(result.count(edge));
#endif
}

#pragma endregion