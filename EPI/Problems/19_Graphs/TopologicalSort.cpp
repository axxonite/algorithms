#include "stdafx.h"
#include "GraphVertex.h"

#define TEST 0

list<GraphVertex*> TopologicalSort(vector<GraphVertex*>& g)
{
	list<GraphVertex*> result;
	return result;
}

#pragma region Test

void TopoSortTest()
{
#if TEST
	unordered_map<string, shared_ptr<GraphVertex>> v;
	v["undershorts"] = make_shared<GraphVertex>(GraphVertex{ "undershorts" });
	v["pants"] = make_shared<GraphVertex>(GraphVertex{ "pants" });
	v["belt"] = make_shared<GraphVertex>(GraphVertex{ "belt" });
	v["socks"] = make_shared<GraphVertex>(GraphVertex{ "socks" });
	v["shoes"] = make_shared<GraphVertex>(GraphVertex{ "shoes" });
	v["watch"] = make_shared<GraphVertex>(GraphVertex{ "watch" });
	v["shirt"] = make_shared<GraphVertex>(GraphVertex{ "shirt" });
	v["tie"] = make_shared<GraphVertex>(GraphVertex{ "tie" });
	v["jacket"] = make_shared<GraphVertex>(GraphVertex{ "jacket" });

	v["undershorts"]->edges.emplace_back(Edge{ v["pants"].get(), 1 });
	v["undershorts"]->edges.emplace_back(Edge{ v["shoes"].get(), 1 });
	v["pants"]->edges.emplace_back(Edge{ v["shoes"].get(), 1 });
	v["pants"]->edges.emplace_back(Edge{ v["belt"].get(), 1 });
	v["belt"]->edges.emplace_back(Edge{ v["jacket"].get(), 1 });
	v["shirt"]->edges.emplace_back(Edge{ v["belt"].get(), 1 });
	v["shirt"]->edges.emplace_back(Edge{ v["tie"].get(), 1 });
	v["tie"]->edges.emplace_back(Edge{ v["jacket"].get(), 1 });
	v["socks"]->edges.emplace_back(Edge{ v["shoes"].get(), 1 });

	vector<GraphVertex*> G;
	G.emplace_back(v["shirt"].get());
	G.emplace_back(v["tie"].get());
	G.emplace_back(v["jacket"].get());
	G.emplace_back(v["belt"].get());
	G.emplace_back(v["watch"].get());
	G.emplace_back(v["undershorts"].get());
	G.emplace_back(v["pants"].get());
	G.emplace_back(v["shoes"].get());
	G.emplace_back(v["socks"].get());

	auto result = TopologicalSort(G);
	auto it = result.begin();
	assert((*it)->name == "socks");
	it++;
	assert((*it)->name == "undershorts");
	it++;
	assert((*it)->name == "pants");
	it++;
	assert((*it)->name == "shoes");
	it++;
	assert((*it)->name == "watch");
	it++;
	assert((*it)->name == "shirt");
	it++;
	assert((*it)->name == "tie");
	it++;
	assert((*it)->name == "belt");
	it++;
	assert((*it)->name == "jacket");
	it++;
#endif
}

#pragma endregion