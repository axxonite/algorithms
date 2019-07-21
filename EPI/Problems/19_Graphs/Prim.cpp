#include "stdafx.h"
#include "GraphVertex.h"
#include "Problems/Data Structures/MSTEdge.h"

// #define TEST

typedef MSTEdge<GraphVertex> MSTPrimEdge;

struct HashEdge
{
	size_t operator () (const MSTPrimEdge& edge) const
	{
		return hash<size_t>()(edge.weight ^ hash<string>{}(edge.src->name) ^ hash<string>{}(edge.dest->name));
	}

};

// Prim is the one that resembles Dijkstra.
unordered_set<MSTPrimEdge, HashEdge> Prim(vector<shared_ptr<GraphVertex>> g, int root)
{
	unordered_set<MSTPrimEdge, HashEdge> result;
  return result;
}

#pragma region Test

MSTPrimEdge AddEdge(MSTPrimEdge edge)
{
	MSTPrimEdge primEdge = edge;
	primEdge.src->edges.emplace_back(Edge{ edge.dest, edge.weight });
	primEdge.dest->edges.emplace_back(Edge{ edge.src, edge.weight });
	return primEdge;
}

void MSTPrimTest()
{
#ifdef TEST
	const auto a = make_shared<GraphVertex>(GraphVertex{ "a" });
	const auto b = make_shared<GraphVertex>(GraphVertex{ "b" });
	const auto c = make_shared<GraphVertex>(GraphVertex{ "c" });
	const auto d = make_shared<GraphVertex>(GraphVertex{ "d" });
	const auto e = make_shared<GraphVertex>(GraphVertex{ "e" });
	const auto f = make_shared<GraphVertex>(GraphVertex{ "f" });
	const auto g = make_shared<GraphVertex>(GraphVertex{ "g" });
	const auto h = make_shared<GraphVertex>(GraphVertex{ "h" });
	const auto i = make_shared<GraphVertex>(GraphVertex{ "i" });
	AddEdge(MSTPrimEdge{ a.get(), b.get(), 4 });
	AddEdge(MSTPrimEdge{ c.get(), d.get(), 7 });
	AddEdge(MSTPrimEdge{ c.get(), i.get(), 2 });
	AddEdge(MSTPrimEdge{ c.get(), f.get(), 4 });
	AddEdge(MSTPrimEdge{ d.get(), e.get(), 9 });
	AddEdge(MSTPrimEdge{ g.get(), h.get(), 1 });
	AddEdge(MSTPrimEdge{ f.get(), g.get(), 2 });
	AddEdge(MSTPrimEdge{ a.get(), h.get(), 8 });
	AddEdge(MSTPrimEdge{ b.get(), c.get(), 8 });
	AddEdge(MSTPrimEdge{ b.get(), h.get(), 11 });
	AddEdge(MSTPrimEdge{ d.get(), f.get(), 14 });
	AddEdge(MSTPrimEdge{ e.get(), f.get(), 10 });
	AddEdge(MSTPrimEdge{ g.get(), i.get(), 6 });
	AddEdge(MSTPrimEdge{ h.get(), i.get(), 7 });

	auto result = Prim(vector<shared_ptr<GraphVertex>>({ a, b, c, d, e, f, g, h, i }), 0);
	assert(result.size() == 8);
	const auto weight = accumulate(result.begin(), result.end(), 0, [](int value, const MSTPrimEdge& edge) { return value + edge.weight; });
	assert(weight == 37);
#endif
}

#pragma endregion