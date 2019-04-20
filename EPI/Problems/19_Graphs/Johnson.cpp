#include "stdafx.h"
#include "GraphVertex.h"
#include "..\..\Solutions\19_Graphs\19.5_clone_graph_solution.h"
#include "..\..\Solutions\19_Graphs\BellmanFord_solution.h"

#define TEST 0

bool Johnson(vector<GraphVertex*> G)
{
	auto clone = Solutions::CloneGraph(G);
	auto s = make_shared<GraphVertex>(GraphVertex());
	for (auto v : clone)
		s->edges.emplace_back(Edge{ v, 0 });
	clone.emplace_back(s.get());
	if (!Solutions::BellmanFord(clone, clone.size() - 1))
		return false;
	for (auto v : clone)
	{
		for (auto e : v->edges)
			e.weight = e.weight + v->dist - e.dst->dist;
	}
	//for int i = 0; i < G.size(); ++i)
	//{
	//	Solutions::Dijkstra(G, i);
	//}
	return true;
}

#pragma region Test

void JohnsonTest()
{
#if TEST
	unordered_map<char, shared_ptr<GraphVertex>> G;
	G['s'] = make_shared<GraphVertex>(GraphVertex{ 's' });
	G['t'] = make_shared<GraphVertex>(GraphVertex{ 't' });
	G['x'] = make_shared<GraphVertex>(GraphVertex{ 'x' });
	G['y'] = make_shared<GraphVertex>(GraphVertex{ 'y' });
	G['z'] = make_shared<GraphVertex>(GraphVertex{ 'z' });

	G['s']->edges.emplace_back(Edge{ G['t'].get(), 6 });
	G['s']->edges.emplace_back(Edge{ G['y'].get(), 7 });
	G['t']->edges.emplace_back(Edge{ G['x'].get(), 5 });
	G['t']->edges.emplace_back(Edge{ G['y'].get(), 8 });
	G['t']->edges.emplace_back(Edge{ G['z'].get(), -4 });
	G['x']->edges.emplace_back(Edge{ G['t'].get(), -2 });
	G['y']->edges.emplace_back(Edge{ G['x'].get(), -3 });
	G['y']->edges.emplace_back(Edge{ G['z'].get(), 9 });
	G['z']->edges.emplace_back(Edge{ G['s'].get(), 2 });
	G['z']->edges.emplace_back(Edge{ G['x'].get(), 7 });

	vector< GraphVertex*> v;
	v.emplace_back(G['s'].get());
	v.emplace_back(G['t'].get());
	v.emplace_back(G['x'].get());
	v.emplace_back(G['y'].get());
	v.emplace_back(G['z'].get());
	assert(Johnson(v));
	assert(G['s']->dist == 0);
	assert(G['t']->dist == 2);
	assert(G['x']->dist == 4);
	assert(G['y']->dist == 7);
	assert(G['z']->dist == -2);
#endif
}

#pragma endregion