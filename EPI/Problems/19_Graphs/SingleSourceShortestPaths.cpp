#include "stdafx.h"
#include "..\..\Solutions\19_Graphs\TopologicalSort_solution.h"

#define TEST 0

// todo make a shared vertex type for all graphs.
void SingleSourceShortestPath(vector<Solutions::TopoGraphVertex*> G, int src)
{
}

#pragma region Test

void SingleSourceShortestPathTest()
{
#if TEST
	unordered_map<char, shared_ptr<Solutions::TopoGraphVertex>> G;
	G['r'] = make_shared<Solutions::TopoGraphVertex>(Solutions::TopoGraphVertex{ 'r' });
	G['s'] = make_shared<Solutions::TopoGraphVertex>(Solutions::TopoGraphVertex{ 's' });
	G['t'] = make_shared<Solutions::TopoGraphVertex>(Solutions::TopoGraphVertex{ 't' });
	G['x'] = make_shared<Solutions::TopoGraphVertex>(Solutions::TopoGraphVertex{ 'x' });
	G['y'] = make_shared<Solutions::TopoGraphVertex>(Solutions::TopoGraphVertex{ 'y' });
	G['z'] = make_shared<Solutions::TopoGraphVertex>(Solutions::TopoGraphVertex{ 'z' });

	G['r']->edges.emplace_back(Solutions::Edge{ G['s'].get(), 5 });
	G['r']->edges.emplace_back(Solutions::Edge{ G['t'].get(), 3 });
	G['s']->edges.emplace_back(Solutions::Edge{ G['t'].get(), 2 });
	G['s']->edges.emplace_back(Solutions::Edge{ G['x'].get(), 6 });
	G['t']->edges.emplace_back(Solutions::Edge{ G['x'].get(), 7 });
	G['t']->edges.emplace_back(Solutions::Edge{ G['y'].get(), 4 });
	G['t']->edges.emplace_back(Solutions::Edge{ G['z'].get(), 2 });
	G['x']->edges.emplace_back(Solutions::Edge{ G['y'].get(), -1 });
	G['x']->edges.emplace_back(Solutions::Edge{ G['z'].get(), 1 });
	G['y']->edges.emplace_back(Solutions::Edge{ G['z'].get(), -2 });

	vector< Solutions::TopoGraphVertex*> v;
	v.emplace_back(G['s'].get());
	v.emplace_back(G['t'].get());
	v.emplace_back(G['x'].get());
	v.emplace_back(G['y'].get());
	v.emplace_back(G['z'].get());
	SingleSourceShortestPath(v, 0);
	assert(G['r']->dist == numeric_limits<int>::max());
	assert(G['s']->dist == 0);
	assert(G['t']->dist == 2);
	assert(G['x']->dist == 6);
	assert(G['y']->dist == 5);
	assert(G['z']->dist == 3);
#endif
}

#pragma endregion