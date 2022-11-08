#include "stdafx.h"
#include "Solutions/Data Structures/DisjointSet_solution.h"
#include "Problems/Data Structures/MSTEdge.h"
#include "GraphVertex.h"

// #define TEST

struct MSTKruskalGraphVertex;

typedef MSTEdge<MSTKruskalGraphVertex> MSTKruskalEdge;

struct MSTKruskalGraphVertex : Solutions::SetElem
{
	char data{};
	vector<shared_ptr<MSTKruskalEdge>> edges;
};

struct HashEdge
{
	size_t operator () (const shared_ptr<MSTKruskalEdge>& edge) const
	{
		return hash<size_t>()(reinterpret_cast<size_t>(edge.get()));
	}
};

// Kruskal is the union set based solution.
unordered_set<shared_ptr<MSTKruskalEdge>, HashEdge> MstKruskal(vector<shared_ptr<MSTKruskalGraphVertex>> g)
{
	unordered_set<shared_ptr<MSTKruskalEdge>, HashEdge> result;
	return result;
}

#pragma region Test

shared_ptr<MSTKruskalEdge> AddEdge(MSTKruskalEdge edge)
{
	auto ptr = make_shared<MSTKruskalEdge>(edge);
	ptr->src->edges.emplace_back(ptr);
	ptr->dest->edges.emplace_back(ptr);
	return ptr;
}

void MstKruskalTest()
{
#ifdef TEST
	auto a = make_shared<MSTKruskalGraphVertex>();
	auto b = make_shared<MSTKruskalGraphVertex>();
	auto c = make_shared<MSTKruskalGraphVertex>();
	auto d = make_shared<MSTKruskalGraphVertex>();
	auto e = make_shared<MSTKruskalGraphVertex>();
	auto f = make_shared<MSTKruskalGraphVertex>();
	auto g = make_shared<MSTKruskalGraphVertex>();
	auto h = make_shared<MSTKruskalGraphVertex>();
	auto i = make_shared<MSTKruskalGraphVertex>();
	a->data = 'a';
	b->data = 'b';
	c->data = 'c';
	d->data = 'd';
	e->data = 'e';
	f->data = 'f';
	g->data = 'g';
	h->data = 'h';
	i->data = 'i';

	auto goldenResult = unordered_set<shared_ptr<MSTKruskalEdge>, HashEdge>();
	goldenResult.emplace(AddEdge(MSTKruskalEdge{ a.get(), b.get(), 4 }));
	goldenResult.emplace(AddEdge(MSTKruskalEdge{ c.get(), d.get(), 7 }));
	goldenResult.emplace(AddEdge(MSTKruskalEdge{ c.get(), i.get(), 2 }));
	goldenResult.emplace(AddEdge(MSTKruskalEdge{ c.get(), f.get(), 4 }));
	goldenResult.emplace(AddEdge(MSTKruskalEdge{ d.get(), e.get(), 9 }));
	goldenResult.emplace(AddEdge(MSTKruskalEdge{ g.get(), h.get(), 1 }));
	goldenResult.emplace(AddEdge(MSTKruskalEdge{ f.get(), g.get(), 2 }));
	goldenResult.emplace(AddEdge(MSTKruskalEdge{ a.get(), h.get(), 8 }));
	AddEdge(MSTKruskalEdge{ b.get(), c.get(), 8 });
	AddEdge(MSTKruskalEdge{ b.get(), h.get(), 11 });
	AddEdge(MSTKruskalEdge{ d.get(), f.get(), 14 });
	AddEdge(MSTKruskalEdge{ e.get(), f.get(), 10 });
	AddEdge(MSTKruskalEdge{ g.get(), i.get(), 6 });
	AddEdge(MSTKruskalEdge{ h.get(), i.get(), 7 });

  auto result = MstKruskal(vector<shared_ptr<MSTKruskalGraphVertex>>({ a, b, c, d, e, f, g, h, i }));
  assert(result.size() == 8);
  const auto weight = accumulate(result.begin(), result.end(), 0, [](int value, const shared_ptr<MSTKruskalEdge>& edge) { return value + edge->weight; });
  assert(weight == 37);
#endif
}

#pragma endregion