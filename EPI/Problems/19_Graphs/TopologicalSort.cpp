#include "stdafx.h"

#define TEST 0

struct TopoGraphVertex
{
	string name;
	int stage = 0;
	vector<shared_ptr<TopoGraphVertex>> edges;
};

list<TopoGraphVertex*> TopologicalSort(vector<TopoGraphVertex*>& g)
{
	list<TopoGraphVertex*> result;
	return result;
}


#pragma region Test

void TopoSortTest()
{
#if TEST
	unordered_map<string, shared_ptr< TopoGraphVertex>> v;
	v["undershorts"] = make_shared<TopoGraphVertex>(TopoGraphVertex{"undershorts"});
	v["pants"] = make_shared<TopoGraphVertex>(TopoGraphVertex{ "pants" });
	v["belt"] = make_shared<TopoGraphVertex>(TopoGraphVertex{ "belt" });
	v["socks"] = make_shared<TopoGraphVertex>(TopoGraphVertex{ "socks" });
	v["shoes"] = make_shared<TopoGraphVertex>(TopoGraphVertex{ "shoes" });
	v["watch"] = make_shared<TopoGraphVertex>(TopoGraphVertex{ "watch" });
	v["shirt"] = make_shared<TopoGraphVertex>(TopoGraphVertex{ "shirt" });
	v["tie"] = make_shared<TopoGraphVertex>(TopoGraphVertex{ "tie" });
	v["jacket"] = make_shared<TopoGraphVertex>(TopoGraphVertex{ "jacket" });

	v["undershorts"]->edges.emplace_back(v["pants"]);
	v["undershorts"]->edges.emplace_back(v["shoes"]);
	v["pants"]->edges.emplace_back(v["shoes"]);
	v["pants"]->edges.emplace_back(v["belt"]);
	v["belt"]->edges.emplace_back(v["jacket"]);
	v["shirt"]->edges.emplace_back(v["belt"]);
	v["shirt"]->edges.emplace_back(v["tie"]);
	v["tie"]->edges.emplace_back(v["jacket"]);
	v["socks"]->edges.emplace_back(v["shoes"]);

	vector<TopoGraphVertex*> G;
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